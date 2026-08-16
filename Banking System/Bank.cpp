#include "Bank.h"

#include <iostream>

#include "SavingsAccount.h"
#include "CheckingAccount.h"

Bank::Bank()
    : nextAccountNumber(1001) {
}

int Bank::createSavingsAccount(
    const std::string& holderName,
    double initialBalance,
    double minimumBalance
) {
    int accountNumber = nextAccountNumber++;

    accounts.push_back(
        std::make_unique<SavingsAccount>(
            accountNumber,
            holderName,
            initialBalance,
            minimumBalance
        )
    );

    return accountNumber;
}

int Bank::createCheckingAccount(
    const std::string& holderName,
    double initialBalance,
    double overdraftLimit
) {
    int accountNumber = nextAccountNumber++;

    accounts.push_back(
        std::make_unique<CheckingAccount>(
            accountNumber,
            holderName,
            initialBalance,
            overdraftLimit
        )
    );

    return accountNumber;
}

Account* Bank::findAccount(int accountNumber) {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account.get();
        }
    }

    return nullptr;
}

const Account* Bank::findAccount(int accountNumber) const {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account.get();
        }
    }

    return nullptr;
}

void Bank::displayAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts available.\n";
        return;
    }

    std::cout << "\n=== All Accounts ===\n";

    for (const auto& account : accounts) {
        account->display();
    }
}