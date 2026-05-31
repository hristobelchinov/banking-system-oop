#include "../include/Account.h"

Account::Account(const std::string& accountNumber,
                 double balance,
                 const std::string& ownerId)
    : accountNumber(accountNumber),
      balance(balance),
      ownerId(ownerId) {}

void Account::deposit(double amount) {
    if (amount <= 0) {
        return;
    }

    balance += amount;

    transactions.emplace_back(
        "DEP-" + std::to_string(transactions.size() + 1),
        Deposit,
        amount,
        "today",
        "Deposit to account " + accountNumber
    );
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }

    balance -= amount;

    transactions.emplace_back(
        "WDR-" + std::to_string(transactions.size() + 1),
        Withdrawal,
        amount,
        "today",
        "Withdrawal from account " + accountNumber
    );

    return true;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

void Account::addTransaction(Transaction transaction) {
    transactions.push_back(transaction);
}

std::vector<Transaction> Account::getTransactionHistory() const {
    return transactions;
}