#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double minimumBalance;

public:
    CheckingAccount(const std::string& accountNumber,
                    double balance,
                    const std::string& ownerId,
                    double minimumBalance);

    bool withdraw(double amount) override;

    std::string getAccountType() const override;
};

#endif