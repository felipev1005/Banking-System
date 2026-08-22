#include "Account.h"

#include <iomanip>
#include <iostream>

Account::Account()
    : accountNumber(0),
    holderName("Unknown"),
    balance(0.0) {
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

const std::vector<Transaction>& Account::getTransactions() const {
    return transactions;
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
}

void Account::addTransaction(
    const std::string& type,
    double amount
) {
    transactions.emplace_back(
        type,
        amount,
        balance
    );
}

void Account::deposit(double amount) {
    if (amount <= 0.0) {
        std::cout << "Invalid deposit amount.\n";
        return;
    }

    balance += amount;

    addTransaction(
        "Deposit",
        amount
    );

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

    addTransaction(
        "Withdrawal",
        amount
    );

    std::cout << "Withdrawal successful.\n";

    return true;
}

void Account::display() const {
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Holder Name: " << holderName << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balance: $" << balance << '\n';
}

void Account::displayTransactionHistory() const {
    std::cout << "\n=== Transaction History ===\n";
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Holder Name: " << holderName << '\n';

    if (transactions.empty()) {
        std::cout << "No transactions available.\n";
        return;
    }

    for (std::size_t i = 0; i < transactions.size(); ++i) {
        std::cout << "\nTransaction #" << i + 1 << '\n';
        std::cout << "----------------------\n";

        transactions[i].display();
    }
}