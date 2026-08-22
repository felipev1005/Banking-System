#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

#include "Transaction.h"

class Account {
private:
    int accountNumber;
    std::string holderName;
    double balance;

    std::vector<Transaction> transactions;

protected:
    void setBalance(double newBalance);

    void addTransaction(
        const std::string& type,
        double amount
    );

public:
    Account();
    Account(
        int accountNumber,
        const std::string& holderName,
        double balance = 0.0
    );

    virtual ~Account() = default;

    int getAccountNumber() const;
    std::string getHolderName() const;
    double getBalance() const;

    const std::vector<Transaction>& getTransactions() const;

    void deposit(double amount);

    virtual bool withdraw(double amount);
    virtual void display() const;

    void displayTransactionHistory() const;
};

#endif