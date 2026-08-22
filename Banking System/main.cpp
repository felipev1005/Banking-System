#include <iostream>
#include <limits>
#include <string>

#include "Bank.h"

void clearInputBuffer() {
    std::cin.clear();

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );
}

int getIntegerInput(const std::string& prompt) {
    int value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            clearInputBuffer();
            return value;
        }

        std::cout
            << "Invalid input. Please enter a number.\n";

        clearInputBuffer();
    }
}

double getDoubleInput(const std::string& prompt) {
    double value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            clearInputBuffer();
            return value;
        }

        std::cout
            << "Invalid input. Please enter a valid amount.\n";

        clearInputBuffer();
    }
}

void displayMenu() {
    std::cout << "\n============================\n";
    std::cout << "       BANKING SYSTEM\n";
    std::cout << "============================\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Transfer Money\n";
    std::cout << "5. View Account\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. View All Accounts\n";
    std::cout << "8. Exit\n";
    std::cout << "============================\n";
}

void createAccount(Bank& bank) {
    std::string holderName;

    std::cout << "\n=== Create Account ===\n";

    std::cout << "Enter account holder name: ";
    std::getline(std::cin, holderName);

    if (holderName.empty()) {
        std::cout
            << "Account holder name cannot be empty.\n";

        return;
    }

    std::cout << "\nAccount Types:\n";
    std::cout << "1. Savings Account\n";
    std::cout << "2. Checking Account\n";

    int accountType =
        getIntegerInput("Choose account type: ");

    double initialBalance =
        getDoubleInput("Enter initial balance: $");

    if (initialBalance < 0.0) {
        std::cout
            << "Initial balance cannot be negative.\n";

        return;
    }

    if (accountType == 1) {
        double minimumBalance =
            getDoubleInput("Enter minimum balance: $");

        if (minimumBalance < 0.0) {
            std::cout
                << "Minimum balance cannot be negative.\n";

            return;
        }

        if (minimumBalance > initialBalance) {
            std::cout
                << "Minimum balance cannot exceed initial balance.\n";

            return;
        }

        int accountNumber =
            bank.createSavingsAccount(
                holderName,
                initialBalance,
                minimumBalance
            );

        std::cout
            << "\nSavings account created successfully.\n";

        std::cout
            << "Account Number: "
            << accountNumber << '\n';
    }
    else if (accountType == 2) {
        double overdraftLimit =
            getDoubleInput("Enter overdraft limit: $");

        if (overdraftLimit < 0.0) {
            std::cout
                << "Overdraft limit cannot be negative.\n";

            return;
        }

        int accountNumber =
            bank.createCheckingAccount(
                holderName,
                initialBalance,
                overdraftLimit
            );

        std::cout
            << "\nChecking account created successfully.\n";

        std::cout
            << "Account Number: "
            << accountNumber << '\n';
    }
    else {
        std::cout << "Invalid account type.\n";
    }
}

void depositMoney(Bank& bank) {
    std::cout << "\n=== Deposit Money ===\n";

    int accountNumber =
        getIntegerInput(
            "Enter account number: "
        );

    double amount =
        getDoubleInput(
            "Enter deposit amount: $"
        );

    bank.depositToAccount(
        accountNumber,
        amount
    );
}

void withdrawMoney(Bank& bank) {
    std::cout << "\n=== Withdraw Money ===\n";

    int accountNumber =
        getIntegerInput(
            "Enter account number: "
        );

    double amount =
        getDoubleInput(
            "Enter withdrawal amount: $"
        );

    bank.withdrawFromAccount(
        accountNumber,
        amount
    );
}

void transferMoney(Bank& bank) {
    std::cout << "\n=== Transfer Money ===\n";

    int fromAccountNumber =
        getIntegerInput(
            "Enter source account number: "
        );

    int toAccountNumber =
        getIntegerInput(
            "Enter destination account number: "
        );

    double amount =
        getDoubleInput(
            "Enter transfer amount: $"
        );

    bank.transferMoney(
        fromAccountNumber,
        toAccountNumber,
        amount
    );
}

void viewAccount(const Bank& bank) {
    std::cout << "\n=== View Account ===\n";

    int accountNumber =
        getIntegerInput(
            "Enter account number: "
        );

    bank.displayAccount(accountNumber);
}

void viewTransactionHistory(const Bank& bank) {
    std::cout
        << "\n=== View Transaction History ===\n";

    int accountNumber =
        getIntegerInput(
            "Enter account number: "
        );

    bank.displayTransactionHistory(
        accountNumber
    );
}

int main() {
    Bank bank;

    bool running = true;

    while (running) {
        displayMenu();

        int choice =
            getIntegerInput(
                "Choose an option: "
            );

        switch (choice) {
        case 1:
            createAccount(bank);
            break;

        case 2:
            depositMoney(bank);
            break;

        case 3:
            withdrawMoney(bank);
            break;

        case 4:
            transferMoney(bank);
            break;

        case 5:
            viewAccount(bank);
            break;

        case 6:
            viewTransactionHistory(bank);
            break;

        case 7:
            bank.displayAllAccounts();
            break;

        case 8:
            std::cout
                << "\nThank you for using the Banking System.\n";

            running = false;
            break;

        default:
            std::cout
                << "Invalid option. Please choose between 1 and 8.\n";
        }
    }

    return 0;
}