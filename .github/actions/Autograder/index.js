const core = require('@actions/core');
const github = require('@actions/github');
const fs = require('fs');
const { exec } = require('child_process');

// Main function
async function run() {
  try {
    await core.group('ValidatorTest', async () => {
      await runValidatorTest();
    });

    const tests = loadAutogradingConfig('./.github/actions/Autograder/autograding.json');

    let totalPoints = 0;
    let maxPoints = 0;

    await core.group('Starting Autograding', async () => {
      for (const exercise of tests.exercises) {
        await core.group(`Running tests for exercise: ${exercise.name}`, async () => {
          for (const test of exercise.tests) {
            core.info(`Starting test: ${test.name}`);
            maxPoints += test.points;

            const result = await runTest(exercise, test);

            if (result.success) {
              totalPoints += test.points;
              core.notice(`Test ${test.name} passed. +${test.points} points.`);
            } else {
              core.warning(`Test ${test.name} failed: ${test.message}`);
              core.error(`Detailed Error: ${result.details}`);
            }
          }
        });
      }
    });

    await updateCheckRun(totalPoints, maxPoints);
  } catch (error) {
    core.error(`Critical error during autograding: ${error.message}`);
    core.setFailed(error.message);
  }
}

// Run the ValidatorTest to ensure infrastructure is functional
async function runValidatorTest() {
  const validatorTest = {
    name: "ValidatorTest",
    tests: [
      { name: "Basic Addition Test", input: "5", expected_output: "10", points: 0 }
    ]
  };

  for (const test of validatorTest.tests) {
    core.info(`Running ValidatorTest: ${test.name}`);
    const result = await runTest(validatorTest, test);

    if (result.success) {
      core.notice(`ValidatorTest passed: ${test.name}`);
    } else {
      core.error(`ValidatorTest failed: ${test.name}, details: ${result.details}`);
      throw new Error("ValidatorTest failed. Stopping pipeline.");
    }
  }
}

// Load the test configuration from autograding.json
function loadAutogradingConfig(path) {
  try {
    const rawData = fs.readFileSync(path);
    return JSON.parse(rawData);
  } catch (error) {
    core.error(`Error loading autograding configuration: ${error.message}`);
    core.setFailed(error.message);
    throw error;
  }
}

// Execute a test by running the .exe with the given parameters
function runTest(exercise, test) {
  return new Promise((resolve) => {
    const input = test.input ? `"${test.input}"` : '';
    const output = test.expected_output ? `"${test.expected_output}"` : '';
    const command = `x64\\Autograder\\Exercises.exe ${exercise.name} ${input} ${output}`.trim();

    core.debug(`Executing command: ${command}`);

    exec(command, (error, stdout, stderr) => {
      if (error) {
        resolve({ success: false, message: stderr.trim() || error.message, details: stderr });
      } else {
        const exitCode = error ? error.code : 0; // Capture the C++ return code
if (exitCode === 0) {
          resolve({ success: true, message: "C++ program exited successfully." });
        } else {
          resolve({ success: false, message: `C++ program failed with exit code ${exitCode}.`, details: stderr.trim() });
        }
      }
    });
  });
}

// Update the check run on GitHub with the test results
async function updateCheckRun(totalPoints, maxPoints) {
  try {
    const token = process.env.GITHUB_TOKEN;
    if (!token) {
      core.setFailed("GitHub token not found");
      return;
    }

    const octokit = github.getOctokit(token);
    const [owner, repo] = process.env.GITHUB_REPOSITORY.split('/');
    const runId = process.env.GITHUB_RUN_ID;

    const workflowRunResponse = await octokit.rest.actions.getWorkflowRun({
      owner,
      repo,
      run_id: runId,
    });

    const checkSuiteUrl = workflowRunResponse.data.check_suite_url;
    const checkSuiteId = parseInt(checkSuiteUrl.match(/[0-9]+$/)[0], 10);

    const checkRunsResponse = await octokit.rest.checks.listForSuite({
      owner,
      repo,
      check_name: 'Autograding',
      check_suite_id: checkSuiteId,
    });

    const checkRun = checkRunsResponse.data.total_count === 1 && checkRunsResponse.data.check_runs[0];
    if (!checkRun) {
      core.setFailed('Check run not found.');
      return;
    }

    const text = `Points ${totalPoints}/${maxPoints}`;
    await core.group('Updating GitHub Check', async () => {
      await octokit.rest.checks.update({
        owner,
        repo,
        check_run_id: checkRun.id,
        output: {
          title: 'Autograding',
          summary: text,
          text: JSON.stringify({ totalPoints, maxPoints }, null, 2),
          annotations: [
            {
              path: '.github/actions/Autograder/autograding.json',
              start_line: 1,
              end_line: 1,
              annotation_level: 'notice',
              message: text,
              title: 'Autograding complete',
            },
          ],
        },
      });
    });

  } catch (error) {
    core.error(`Error updating check run: ${error.message}`);
    core.setFailed(error.message);
  }
}

run();
