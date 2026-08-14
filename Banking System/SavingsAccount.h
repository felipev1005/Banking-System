#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double minimumBalance;

public:
    SavingsAccount(
        int accountNumber,
        const std::string& holderName,
        double balance,
        double minimumBalance
    );

    bool withdraw(double amount) override;
    void display() const override;
};

#endif
