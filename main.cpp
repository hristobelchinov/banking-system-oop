#include <iostream>
#include <iomanip>

#include "include/Bank.h"
#include "include/SavingsAccount.h"
#include "include/CheckingAccount.h"

std::string transactionTypeToString(TransactionType type) {
    switch (type) {
        case Deposit:
            return "Deposit";
        case Withdrawal:
            return "Withdrawal";
        case Transfer:
            return "Transfer";
        default:
            return "Unknown";
    }
}

void printAccountInfo(Account* account) {
    if (account == nullptr) {
        return;
    }

    std::cout << "Account number: " << account->getAccountNumber() << '\n';
    std::cout << "Account type: " << account->getAccountType() << '\n';
    std::cout << "Balance: "
              << std::fixed << std::setprecision(2)
              << account->getBalance()
              << " BGN\n";
}

void printTransactionHistory(Account* account) {
    if (account == nullptr) {
        return;
    }

    std::cout << "\nTransaction history for account "
              << account->getAccountNumber()
              << ":\n";

    std::vector<Transaction> history = account->getTransactionHistory();

    if (history.empty()) {
        std::cout << "No transactions.\n";
        return;
    }

    for (const Transaction& transaction : history) {
        std::cout << "- "
                  << transaction.getDate()
                  << " | "
                  << transactionTypeToString(transaction.getType())
                  << " | "
                  << std::fixed << std::setprecision(2)
                  << transaction.getAmount()
                  << " | "
                  << transaction.getDescription()
                  << '\n';
    }
}

int main() {
    Bank bank("OOP Bank");

    Client firstClient("101", "Ivan Ivanov", "Sofia, Bulgaria");
    Client secondClient("102", "Maria Petrova", "Plovdiv, Bulgaria");

    SavingsAccount savings("SA-1001", 1000.0, "101", 0.05);
    CheckingAccount checking("CA-2001", 800.0, "102", 100.0);

    firstClient.addAccount(&savings);
    secondClient.addAccount(&checking);

    bank.addClient(firstClient);
    bank.addClient(secondClient);

    savings.deposit(250.0);
    checking.withdraw(150.0);
    savings.applyInterest();

    bank.transfer(&savings, &checking, 300.0);

    std::cout << "Bank: " << bank.getName() << "\n\n";

    printAccountInfo(&savings);
    std::cout << '\n';
    printAccountInfo(&checking);

    printTransactionHistory(&savings);
    printTransactionHistory(&checking);

    Client* foundClient = bank.findClient("101");

    if (foundClient != nullptr) {
        std::cout << "\nFound client: "
                  << foundClient->getName()
                  << '\n';
    }

    return 0;
}