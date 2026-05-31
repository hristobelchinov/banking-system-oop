#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Account.h"

class Client {
private:
    std::string id;
    std::string name;
    std::string address;
    std::vector<Account*> accounts;

public:
    Client();

    Client(const std::string& id,
           const std::string& name,
           const std::string& address);

    void addAccount(Account* account);
    void removeAccount(std::string accountNumber);

    std::vector<Account*> getAccounts() const;

    std::string getName() const;
    std::string getId() const;
    std::string getAddress() const;
};

#endif