#include "CheckingAccount.h"
#include <iomanip>
#include <iostream>

CheckingAccount::CheckingAccount(
    int accountNumber,
    const std::string& holderName,
    double balance,
    double overdraftLimit
)
    : Account(accountNumber, holderName, balance),
    overdraftLimit(overdraftLimit >= 0.0 ? overdraftLimit : 0.0) {
}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0.0) {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }

    double remainingBalance = getBalance() - amount;

    if (remainingBalance < -overdraftLimit) {
        std::cout << "Withdrawal denied. Overdraft limit exceeded.\n";
        return false;
    }

    setBalance(remainingBalance);

    std::cout << "Withdrawal successful.\n";

    return true;
}

void CheckingAccount::display() const {
    std::cout << "\n--- Checking Account ---\n";

    Account::display();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Overdraft Limit: $" << overdraftLimit << '\n';
}