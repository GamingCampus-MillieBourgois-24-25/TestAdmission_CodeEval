#include "ValidatorTest.h"

#include "ExerciseTest.h"

bool ValidatorTest::EvalInternal(const int& _input, const int& _expected_output)
{
	const int result = ExecuteExercise(_input);

	if (result == _expected_output)
	{
		LogSuccess(std::to_string(_input), std::to_string(_expected_output), std::to_string(result));
		return true;
	}

	LogFailure(std::to_string(_input), std::to_string(_expected_output), std::to_string(result));
	return false;
}

int ValidatorTest::ExecuteExercise(const int& _input)
{
	constexpr ExerciseTest solution;
	return solution.Add(_input, _input);
}
