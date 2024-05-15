#include <iostream>
#include "Account.h"

int main() {
    Account test_account;
    test_account.set_name("Test account");
    test_account.set_balance(1'000.0);

    if (test_account.deposit(200.0)) {
        std::cout << "Deposit OK" << std::endl;
    }

    if (test_account.withdraw(500.0)) {
        std::cout << "Withdrawal OK" << std::endl;
    } else {
        printf("Insufficient funds\n");
    }

    if (test_account.withdraw(1'500.0)) {
        printf("Withdrawal OK\n");
    } else {
        printf("Insufficient funds\n");
    }
    return 0;
}