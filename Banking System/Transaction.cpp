#include "Transaction.h"

#include <iomanip>
#include <iostream>

Transaction::Transaction(
    const std::string& type,
    double amount,
    double balanceAfter
)
    : type(type),
    amount(amount),
    balanceAfter(balanceAfter) {
}

std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

double Transaction::getBalanceAfter() const {
    return balanceAfter;
}

void Transaction::display() const {
    std::cout << "Type: " << type << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Amount: $" << amount << '\n';
    std::cout << "Balance After: $" << balanceAfter << '\n';
}