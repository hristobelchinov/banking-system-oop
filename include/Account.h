#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
protected:
    std::string accountNumber;
    double balance;
    std::string ownerId;
    std::vector<Transaction> transactions;

public:
    Account(const std::string& accountNumber,
            double balance,
            const std::string& ownerId);

    virtual ~Account() = default;

    void deposit(double amount);
    virtual bool withdraw(double amount);

    double getBalance() const;
    std::string getAccountNumber() const;

    void addTransaction(Transaction transaction);
    std::vector<Transaction> getTransactionHistory() const;

    virtual std::string getAccountType() const = 0;
};

#endif