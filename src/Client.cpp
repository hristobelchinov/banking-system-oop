#include "../include/Client.h"
#include <algorithm>

Client::Client()
    : id(""), name(""), address("") {}

Client::Client(const std::string& id,
               const std::string& name,
               const std::string& address)
    : id(id), name(name), address(address) {}

void Client::addAccount(Account* account) {
    if (account != nullptr) {
        accounts.push_back(account);
    }
}

void Client::removeAccount(std::string accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i] != nullptr &&
            accounts[i]->getAccountNumber() == accountNumber) {
            
            accounts.erase(accounts.begin() + i);
            return;
        }
    }
}

std::vector<Account*> Client::getAccounts() const {
    return accounts;
}

std::string Client::getName() const {
    return name;
}

std::string Client::getId() const {
    return id;
}

std::string Client::getAddress() const {
    return address;
}