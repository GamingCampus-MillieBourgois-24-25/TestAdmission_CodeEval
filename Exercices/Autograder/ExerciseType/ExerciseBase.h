#pragma once

#include <iostream>
#include <string>

#define TEST(TestName) \
class TestName : public Exercise<void, void> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
	TestName() { exerciseName = #TestName; } \
protected: \
	void ExecuteExercise() override; \
	bool EvalInternal() override; \
};

#define TEST_INPUT(TestName, InputType) \
class TestName : public Exercise<InputType, void> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
	TestName() { exerciseName = #TestName; } \
protected: \
	void ExecuteExercise(const InputType& _input) override; \
	bool EvalInternal(const InputType& _input) override; \
};

#define TEST_INPUT_OUTPUT(TestName, InputType, OutputType) \
class TestName : public Exercise<InputType, OutputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
	TestName() { exerciseName = #TestName; } \
protected: \
	OutputType ExecuteExercise(const InputType& _input) override; \
	bool EvalInternal(const InputType& _input, const OutputType& _expected_output) override; \
};

class ExerciseBase
{
public:
	virtual ~ExerciseBase() = default;

	virtual bool PrepareEval(const std::string& _input, const std::string& _expected_output) = 0;

protected:
	const std::string& GetExerciseName() const
	{
		return exerciseName;
	}

	std::string exerciseName;

	void Log(const std::string& _status, const std::string& _input, const std::string& _expected, const std::string& _result, const std::string& _message = "") const
	{
		std::ostream& stream = (_status == "SUCCESS") ? std::cout : std::cerr;
		stream << "[" << _status << "] Exercise: \"" << exerciseName << "\"";
		if (!_input.empty())
			stream << " | Input: \"" << _input << "\"";
		if (!_expected.empty())
			stream << " | Expected: \"" << _expected << "\"";
		if (!_result.empty())
			stream << " | Result: \"" << _result << "\"";
		if (!_message.empty())
			stream << " | Message: \"" << _message << "\"";
		stream << std::endl;
	}

	void LogSuccess(const std::string& _input, const std::string& _expected, const std::string& _result, const std::string& _message = "") const
	{
		Log("SUCCESS", _input, _expected, _result, _message);
	}

	void LogFailure(const std::string& _input, const std::string& _expected, const std::string& _result, const std::string& _message = "") const
	{
		Log("FAILURE", _input, _expected, _result, _message);
	}
};
