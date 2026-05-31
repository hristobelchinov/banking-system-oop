#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accountNumber,
                   double balance,
                   const std::string& ownerId,
                   double interestRate);

    double calculateInterest() const;
    void applyInterest();

    std::string getAccountType() const override;
};

#endif