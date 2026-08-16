#ifndef BANK_H
#define BANK_H

#include <memory>
#include <string>
#include <vector>

#include "Account.h"

class Bank {
private:
    std::vector<std::unique_ptr<Account>> accounts;
    int nextAccountNumber;

public:
    Bank();

    int createSavingsAccount(
        const std::string& holderName,
        double initialBalance,
        double minimumBalance
    );

    int createCheckingAccount(
        const std::string& holderName,
        double initialBalance,
        double overdraftLimit
    );

    Account* findAccount(int accountNumber);
    const Account* findAccount(int accountNumber) const;

    void displayAllAccounts() const;
};

#endif
