#include "../include/CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string& accountNumber,
                                 double balance,
                                 const std::string& ownerId,
                                 double minimumBalance)
    : Account(accountNumber, balance, ownerId),
      minimumBalance(minimumBalance) {}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0 || balance - amount < minimumBalance) {
        return false;
    }

    balance -= amount;

    transactions.emplace_back(
        "WDR-" + std::to_string(transactions.size() + 1),
        Withdrawal,
        amount,
        "today",
        "Withdrawal from checking account " + accountNumber
    );

    return true;
}

std::string CheckingAccount::getAccountType() const {
    return "CheckingAccount";
}