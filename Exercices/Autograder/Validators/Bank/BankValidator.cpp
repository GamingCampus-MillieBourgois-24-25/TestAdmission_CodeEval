#include "BankValidator.h"
#include "Exercises/Bank/Bank.h"

bool BankValidator::EvalInternal(const int& _input)
{
	switch (_input)
	{
	case 1:
		return TestAddAccounts();
	case 2:
		return TestDeposit();
	case 3:
		return TestWithdraw();
	case 4:
		return TestTransferValid();
	case 5:
		return TestTransferInvalid();
	default:
		LogFailure(std::to_string(_input), "1-5", "Invalid input", "Invalid test ID provided.");
		return false;
	}
}

bool BankValidator::TestAddAccounts() const
{
	Bank bank;
	bank.AddAccount(1, 1000.0);
	bank.AddAccount(2, 500.0);

	const double balance1 = bank.GetBalance(1);
	const double balance2 = bank.GetBalance(2);

	bool success = true;

	if (balance1 == 1000.0)
	{
		LogSuccess("AddAccount(1, 1000.0)", "1000.0", std::to_string(balance1), "Test AddAccounts - Balance for account 1 is correct.");
	}
	else
	{
		LogFailure("AddAccount(1, 1000.0)", "1000.0", std::to_string(balance1), "Test AddAccounts - Incorrect balance for account 1.");
		success = false;
	}

	if (balance2 == 500.0)
	{
		LogSuccess("AddAccount(2, 500.0)", "500.0", std::to_string(balance2), "Test AddAccounts - Balance for account 2 is correct.");
	}
	else
	{
		LogFailure("AddAccount(2, 500.0)", "500.0", std::to_string(balance2), "Test AddAccounts - Incorrect balance for account 2.");
		success = false;
	}

	return success;
}

bool BankValidator::TestDeposit() const
{
	Bank bank;
	bank.AddAccount(1, 1000.0);
	bank.Deposit(1, 200.0);

	const double balance = bank.GetBalance(1);
	if (balance == 1200.0)
	{
		LogSuccess("Deposit(1, 200.0)", "1200.0", std::to_string(balance), "Test Deposit - Balance after deposit is correct.");
		return true;
	}

	LogFailure("Deposit(1, 200.0)", "1200.0", std::to_string(balance), "Test Deposit - Balance after deposit is incorrect.");
	return false;
}

bool BankValidator::TestWithdraw() const
{
	Bank bank;
	bank.AddAccount(2, 500.0);
	bank.Withdraw(2, 100.0);

	const double balance = bank.GetBalance(2);
	if (balance == 400.0)
	{
		LogSuccess("Withdraw(2, 100.0)", "400.0", std::to_string(balance), "Test Withdraw - Balance after withdrawal is correct.");
		return true;
	}

	LogFailure("Withdraw(2, 100.0)", "400.0", std::to_string(balance), "Test Withdraw - Balance after withdrawal is incorrect.");
	return false;
}

bool BankValidator::TestTransferValid() const
{
	Bank bank;
	bank.AddAccount(1, 1000.0);
	bank.AddAccount(2, 500.0);
	bank.Transfer(1, 2, 300.0);

	const double balance1 = bank.GetBalance(1);
	const double balance2 = bank.GetBalance(2);

	bool success = true;

	if (balance1 == 700.0)
	{
		LogSuccess("Transfer(1, 2, 300.0)", "700.0", std::to_string(balance1), "Test TransferValid - Balance for account 1 after transfer is correct.");
	}
	else
	{
		LogFailure("Transfer(1, 2, 300.0)", "700.0", std::to_string(balance1), "Test TransferValid - Balance for account 1 after transfer is incorrect.");
		success = false;
	}

	if (balance2 == 800.0)
	{
		LogSuccess("Transfer(1, 2, 300.0)", "800.0", std::to_string(balance2), "Test TransferValid - Balance for account 2 after transfer is correct.");
	}
	else
	{
		LogFailure("Transfer(1, 2, 300.0)", "800.0", std::to_string(balance2), "Test TransferValid - Balance for account 2 after transfer is incorrect.");
		success = false;
	}

	return success;
}

bool BankValidator::TestTransferInvalid() const
{
	Bank bank;
	bank.AddAccount(1, 1000.0);
	bank.AddAccount(2, 500.0);

	try
	{
		bank.Transfer(2, 1, 1000.0); // Invalid transfer
		LogFailure("Transfer(2, 1, 1000.0)", "Exception", "No exception", "Test TransferInvalid - No exception was thrown for invalid transfer.");
		return false;
	}
	catch (const std::exception&)
	{
		LogSuccess("Transfer(2, 1, 1000.0)", "Exception", "Exception", "Test TransferInvalid - Exception was correctly thrown for invalid transfer.");
		return true;
	}
}
