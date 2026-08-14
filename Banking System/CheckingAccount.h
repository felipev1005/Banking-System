#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(
        int accountNumber,
        const std::string& holderName,
        double balance,
        double overdraftLimit
    );

    bool withdraw(double amount) override;
    void display() const override;
};

#endif
