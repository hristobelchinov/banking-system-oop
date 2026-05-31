#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "TransactionType.h"

class Transaction {
private:
    std::string transactionId;
    TransactionType type;
    double amount;
    std::string date;
    std::string description;

public:
    Transaction();

    Transaction(const std::string& transactionId,
                TransactionType type,
                double amount,
                const std::string& date,
                const std::string& description);

    double getAmount() const;
    TransactionType getType() const;
    std::string getDate() const;
    std::string getDescription() const;
    std::string getTransactionId() const;
};

#endif