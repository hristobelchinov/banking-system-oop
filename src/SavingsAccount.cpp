#include "../include/SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& accountNumber,
                               double balance,
                               const std::string& ownerId,
                               double interestRate)
    : Account(accountNumber, balance, ownerId),
      interestRate(interestRate) {}

double SavingsAccount::calculateInterest() const {
    return balance * interestRate;
}

void SavingsAccount::applyInterest() {
    double interest = calculateInterest();

    if (interest > 0) {
        balance += interest;

        transactions.emplace_back(
            "INT-" + std::to_string(transactions.size() + 1),
            Deposit,
            interest,
            "today",
            "Interest applied to savings account " + accountNumber
        );
    }
}

std::string SavingsAccount::getAccountType() const {
    return "SavingsAccount";
}