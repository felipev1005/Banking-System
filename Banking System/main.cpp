#include <iostream>

#include "Bank.h"

int main() {
    Bank bank;

    int savingsAccountNumber = bank.createSavingsAccount(
        "Alice Johnson",
        1000.0,
        200.0
    );

    int checkingAccountNumber = bank.createCheckingAccount(
        "Michael Smith",
        500.0,
        300.0
    );

    std::cout << "Savings account created with account number: "
        << savingsAccountNumber << '\n';

    std::cout << "Checking account created with account number: "
        << checkingAccountNumber << '\n';

    bank.displayAllAccounts();

    std::cout << "\n=== Account Search Test ===\n";

    Account* account = bank.findAccount(savingsAccountNumber);

    if (account != nullptr) {
        std::cout << "Account found:\n";
        account->display();
    }
    else {
        std::cout << "Account not found.\n";
    }

    std::cout << "\nSearching for account 9999...\n";

    account = bank.findAccount(9999);

    if (account != nullptr) {
        account->display();
    }
    else {
        std::cout << "Account not found.\n";
    }

    return 0;
}