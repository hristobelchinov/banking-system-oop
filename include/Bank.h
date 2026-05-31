#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Client.h"

class Bank {
private:
    std::string name;
    std::vector<Client> clients;

public:
    Bank(const std::string& name);

    void addClient(Client client);
    void removeClient(std::string clientId);

    Client* findClient(std::string clientId);

    bool transfer(Account* fromAccount,
                  Account* toAccount,
                  double amount);

    std::string getName() const;
    std::vector<Client> getClients() const;
};

#endif