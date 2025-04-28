#pragma once

/**
 * Exercise: Bank Account Management System
 *
 * In this exercise, you will implement a class called `Bank` that simulates a simple banking system. The `Bank` class should allow managing multiple accounts, handling
 * deposits, withdrawals, and transfers between accounts. You will need to use proper encapsulation to protect the internal data of the class.
 *
 * Requirements:
 * --------------
 * 1. **Class Name:** Bank
 * 2. **Attributes (Private):**
 *    - A data structure (e.g., std::unordered_map) to store account details:
 *      each account has a unique account number (integer) and a balance (double).
 * 
 * 3. **Public Methods:**
 *    - `void AddAccount(int accountNumber, double initialBalance)`
 *      - Adds a new account to the bank with the specified account number and an
 *        initial balance.
 *      - If the account number already exists, it should throw an exception.
 *
 *    - `double GetBalance(int accountNumber)`
 *      - Returns the balance of the specified account.
 *      - Throws an exception if the account does not exist.
 *
 *    - `void Deposit(int accountNumber, double amount)`
 *      - Adds the specified amount to the balance of the given account.
 *      - The amount must be greater than zero, otherwise throw an exception.
 *
 *    - `void Withdraw(int accountNumber, double amount)`
 *      - Deducts the specified amount from the balance of the given account.
 *      - Ensure the balance does not go below zero; otherwise, throw an exception.
 *
 *    - `void Transfer(int fromAccount, int toAccount, double amount)`
 *      - Transfers the specified amount from one account to another.
 *      - Ensure both accounts exist and that the `fromAccount` has sufficient funds.
 *      - Throws exceptions for invalid cases.
 *
 * Constraints:
 * ------------
 * - Use encapsulation to ensure that account details are protected.
 * - Handle all edge cases with proper exceptions (e.g., non-existent accounts, insufficient funds, invalid amounts).
 *
 * Example Use Cases:
 * ------------------
 * 1. Adding accounts:
 *      Bank bank;
 *      bank.AddAccount(1, 1000.0);
 *      bank.AddAccount(2, 500.0);
 *
 * 2. Retrieving balances:
 *      double balance = bank.GetBalance(1); // Should return 1000.0
 *
 * 3. Depositing money:
 *      bank.Deposit(1, 200.0); // Account 1's balance becomes 1200.0
 *
 * 4. Withdrawing money:
 *      bank.Withdraw(2, 100.0); // Account 2's balance becomes 400.0
 *
 * 5. Transferring money:
 *      bank.Transfer(1, 2, 300.0);
 *      // Account 1's balance becomes 900.0
 *      // Account 2's balance becomes 700.0
 *
 * Test Cases:
 * -----------
 * Your implementation will be tested against the following scenarios:
 * 1. Adding accounts with valid and invalid inputs.
 * 2. Retrieving balances for existing and non-existing accounts.
 * 3. Depositing valid and invalid amounts.
 * 4. Withdrawing valid and invalid amounts.
 * 5. Transferring money between valid and invalid accounts.
 *
 * Notes:
 * ------
 * - Ensure your implementation is robust and adheres to the principles of object-oriented programming.
 * - Each method should handle exceptions gracefully and provide meaningful error messages.
 */

class Bank
{
public:
	// To comply with instructions above, you can only rename parameters if needed. Use Bank.cpp to implement the methods.

	void AddAccount(int accountNumber, double initialBalance);
	double GetBalance(int accountNumber);
	void Deposit(int accountNumber, double amount);
	void Withdraw(int accountNumber, double amount);
	void Transfer(int fromAccount, int toAccount, double amount);
};
