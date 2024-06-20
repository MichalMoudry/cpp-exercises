#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(
    std::string acc_name,
    double acc_balance,
    double acc_interest_rate
) : Account{acc_name, acc_balance}, interest_rate{acc_interest_rate} {}

bool SavingsAccount::deposit(double amount) {
    amount += amount * (interest_rate/100);
    return Account::deposit(amount);
}

std::ostream& operator<<(std::ostream& os, const SavingsAccount& sav_account) {
    os << "[Saving account: "
        << sav_account.name << " : "
        << sav_account.balance << ", "
        << sav_account.interest_rate << "%]";
    return os;
}