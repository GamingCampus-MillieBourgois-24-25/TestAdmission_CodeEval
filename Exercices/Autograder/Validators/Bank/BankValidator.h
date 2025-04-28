#pragma once

#include "Autograder/Core.h"

class BankValidator : public Exercise<int, void>
{
public:
	static void Register()
	{
		TestRegistry::RegisterTest("BankValidator", []
		{
			return new BankValidator();
		});
	}

	BankValidator()
	{
		exerciseName = "BankValidator";
	}

protected:
	void ExecuteExercise(const int& _input) override {}
	bool EvalInternal(const int& _input) override;

	bool TestAddAccounts() const;
	bool TestDeposit() const;
	bool TestWithdraw() const;
	bool TestTransferValid() const;
	bool TestTransferInvalid() const;
};
