#include "SavingsAccount.h"

#include <iomanip>
#include <iostream>

SavingsAccount::SavingsAccount(
    int accountNumber,
    const std::string& holderName,
    double balance,
    double minimumBalance
)
    : Account(accountNumber, holderName, balance),
    minimumBalance(minimumBalance >= 0.0 ? minimumBalance : 0.0) {
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0.0) {
        std::cout << "Invalid withdrawal amount.\n";
        return false;
    }

    double remainingBalance = getBalance() - amount;

    if (remainingBalance < minimumBalance) {
        std::cout
            << "Withdrawal denied. Minimum balance must be maintained.\n";

        return false;
    }

    setBalance(remainingBalance);

    addTransaction(
        "Withdrawal",
        amount
    );

    std::cout << "Withdrawal successful.\n";

    return true;
}

void SavingsAccount::display() const {
    std::cout << "\n--- Savings Account ---\n";

    Account::display();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Minimum Balance: $" << minimumBalance << '\n';
}