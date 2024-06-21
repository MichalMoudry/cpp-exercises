#include <iostream>
#include "TrustAccount.h"
#include "CheckingAccount.h"
#include "AccountUtil.h"

/*
1. Add a Checking account class to the Account hierarchy.
    - A checking account has a name and a balance and has a
    fee of $1.50 per withdrawal transaction.
    - Every withdrawal transaction will be assessed this flat fee.

2. Add a Trust account class to the Account hierarchy.
    - A trust account has a name, a balance, and an interest rate.
    - The trust account deposit works just like a savings account deposit.
    However, any deposits of $5000.0 or more will receive a $50.0 bonus
    deposited to the account.
    - The trust account withdrawal should only allow 3 withdrawals per year
    and each of these must be less than 20% of the account balance.
        = 4th deposit needs to fail.
*/

int main() {
    /*// Accounts
    std::vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2'000});
    accounts.push_back(Account {"Curly", 5'000});
    display(accounts);
    deposit(accounts, 1'000);
    withdraw(accounts, 2'000);

    // Savings accounts
    std::vector<SavingsAccount> sav_accounts;
    sav_accounts.push_back(SavingsAccount {});
    sav_accounts.push_back(SavingsAccount {"Test 1"});
    sav_accounts.push_back(SavingsAccount {"Test 2", 2'000});
    sav_accounts.push_back(SavingsAccount {"Test 3", 5'000, 5.0});
    display(sav_accounts);
    deposit(sav_accounts, 1'000);
    withdraw(sav_accounts, 2'000);*/

    CheckingAccount check_acc_1 {"Test checking account"};
    std::cout << check_acc_1 << std::endl;
    check_acc_1.deposit(100);
    std::cout << check_acc_1 << std::endl;
    check_acc_1.withdraw(50);
    std::cout << check_acc_1 << std::endl;
    check_acc_1.withdraw(47.01);
    std::cout << check_acc_1 << std::endl;

    TrustAccount trust_acc_1 {"Test trust account", 2'000};
    std::cout << trust_acc_1 << std::endl;
    trust_acc_1.deposit(5000);
    std::cout << trust_acc_1 << std::endl;
    trust_acc_1.withdraw(100);
    trust_acc_1.withdraw(100);
    trust_acc_1.withdraw(100);
    trust_acc_1.withdraw(100);
    std::cout << trust_acc_1 << std::endl;
    return 0;
}