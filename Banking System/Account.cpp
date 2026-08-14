#include "Account.h"
#include <iomanip>
#include <iostream>

Account::Account()
    : accountNumber(0), holderName("Unknown"), balance(0.0) {
}

Account::Account(
    int accountNumber,
    const std::string& holderName,
    double balance
)
    : accountNumber(accountNumber),
    holderName(holderName),
    balance(balance >= 0.0 ? balance : 0.0) {
}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getHolderName() const {
    return holderName;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
}

void Account::deposit(double amount) {
    if (amount <= 0.0) {
        std::cout << "Invalid deposit amount.\n";
        return;
    }

    balance += amount;
    std::cout << "Deposit successful.\n";
}

bool Account::withdraw(double amount) {
    if (amount <= 0.0) {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }

    if (amount > balance) {
        std::cout << "Insufficient funds.\n";
        return false;
    }

    balance -= amount;
    std::cout << "Withdrawal successful.\n";

    return true;
}

void Account::display() const {
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Holder Name: " << holderName << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balance: $" << balance << '\n';
}