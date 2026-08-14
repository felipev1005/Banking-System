#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string holderName;
    double balance;

protected:
    void setBalance(double newBalance);

public:
    Account();
    Account(int accountNumber, const std::string& holderName, double balance = 0.0);

    virtual ~Account() = default;

    int getAccountNumber() const;
    std::string getHolderName() const;
    double getBalance() const;

    void deposit(double amount);

    virtual bool withdraw(double amount);
    virtual void display() const;
};

#endif