#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <vector>
#include "Account.h"
#include "SavingsAccount.h"

void display(const std::vector<Account>& accounts);
void deposit(std::vector<Account>& accounts, double amount);
void withdraw(std::vector<Account>& accounts, double amount);

void display(const std::vector<SavingsAccount>& accounts);
void deposit(std::vector<SavingsAccount>& accounts, double amount);
void withdraw(std::vector<SavingsAccount>& accounts, double amount);

#endif