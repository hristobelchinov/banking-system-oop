#include "../include/Transaction.h"

Transaction::Transaction()
    : transactionId(""), type(Deposit), amount(0.0), date(""), description("") {}

Transaction::Transaction(const std::string& transactionId,
                         TransactionType type,
                         double amount,
                         const std::string& date,
                         const std::string& description)
    : transactionId(transactionId),
      type(type),
      amount(amount),
      date(date),
      description(description) {}

double Transaction::getAmount() const {
    return amount;
}

TransactionType Transaction::getType() const {
    return type;
}

std::string Transaction::getDate() const {
    return date;
}

std::string Transaction::getDescription() const {
    return description;
}

std::string Transaction::getTransactionId() const {
    return transactionId;
}