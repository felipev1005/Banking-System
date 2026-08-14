#include <iostream>
#include <vector>

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    SavingsAccount savings(
        1001,
        "Diego Felipe",
        1000.0,
        200.0
    );

    CheckingAccount checking(
        1002,
        "Diego Felipe",
        500.0,
        300.0
    );

    std::vector<Account*> accounts;

    accounts.push_back(&savings);
    accounts.push_back(&checking);

    std::cout << "=== Account Details ===\n";

    for (const Account* account : accounts) {
        account->display();
    }

    std::cout << "\n=== Savings Withdrawal Test ===\n";

    savings.withdraw(500.0);
    savings.display();

    std::cout << "\nAttempting withdrawal below minimum balance:\n";

    savings.withdraw(400.0);
    savings.display();

    std::cout << "\n=== Checking Withdrawal Test ===\n";

    checking.withdraw(700.0);
    checking.display();

    std::cout << "\nAttempting withdrawal beyond overdraft limit:\n";

    checking.withdraw(200.0);
    checking.display();

    return 0;
}