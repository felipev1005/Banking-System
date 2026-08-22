#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string type;
    double amount;
    double balanceAfter;

public:
    Transaction(
        const std::string& type,
        double amount,
        double balanceAfter
    );

    std::string getType() const;
    double getAmount() const;
    double getBalanceAfter() const;

    void display() const;
};

#endif
