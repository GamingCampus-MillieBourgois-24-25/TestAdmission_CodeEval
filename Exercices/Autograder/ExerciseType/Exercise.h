#pragma once

#include <stdexcept>

#include "ExerciseBase.h"
#include "Autograder/Helpers.h"

template<typename InputType, typename OutputType>
class Exercise : public ExerciseBase
{
protected:
	bool PrepareEval(const std::string& _input, const std::string& _expected_output) override
	{
		InputType parsed_input = ConvertFromString<InputType>(_input);
		OutputType parsed_expected_output = ConvertFromString<OutputType>(_expected_output);

		return EvalInternal(parsed_input, parsed_expected_output);
	}

	virtual OutputType ExecuteExercise(const InputType& _input) = 0;
	virtual bool EvalInternal(const InputType& _input, const OutputType& _expected_output) = 0;
};

template<typename InputType>
class Exercise<InputType, void> : public ExerciseBase
{
protected:
	bool PrepareEval(const std::string& _input, const std::string& _expected_output) override
	{
		InputType parsed_input = ConvertFromString<InputType>(_input);
		return EvalInternal(parsed_input);
	}

	virtual void ExecuteExercise(const InputType& _input) = 0;
	virtual bool EvalInternal(const InputType& _input) = 0;
};

template<>
class Exercise<void, void> : public ExerciseBase
{
protected:
	bool PrepareEval(const std::string& _input, const std::string& _expected_output) override
	{
		return Eval();
	}

	virtual void ExecuteExercise() = 0;
	virtual bool Eval() = 0;
};
