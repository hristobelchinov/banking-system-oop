#include "../include/Bank.h"
#include <algorithm>

Bank::Bank(const std::string& name)
    : name(name) {}

void Bank::addClient(Client client) {
    clients.push_back(client);
}

void Bank::removeClient(std::string clientId) {
    clients.erase(
        std::remove_if(
            clients.begin(),
            clients.end(),
            [&clientId](const Client& client) {
                return client.getId() == clientId;
            }
        ),
        clients.end()
    );
}

Client* Bank::findClient(std::string clientId) {
    for (Client& client : clients) {
        if (client.getId() == clientId) {
            return &client;
        }
    }

    return nullptr;
}

bool Bank::transfer(Account* fromAccount,
                    Account* toAccount,
                    double amount) {
    if (fromAccount == nullptr || toAccount == nullptr || amount <= 0) {
        return false;
    }

    if (!fromAccount->withdraw(amount)) {
        return false;
    }

    toAccount->deposit(amount);

    fromAccount->addTransaction(
        Transaction(
            "TRF-OUT-" + std::to_string(fromAccount->getTransactionHistory().size() + 1),
            Transfer,
            amount,
            "today",
            "Transfer to account " + toAccount->getAccountNumber()
        )
    );

    toAccount->addTransaction(
        Transaction(
            "TRF-IN-" + std::to_string(toAccount->getTransactionHistory().size() + 1),
            Transfer,
            amount,
            "today",
            "Transfer from account " + fromAccount->getAccountNumber()
        )
    );

    return true;
}

std::string Bank::getName() const {
    return name;
}

std::vector<Client> Bank::getClients() const {
    return clients;
}