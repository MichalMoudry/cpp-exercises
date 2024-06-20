#include "Account.h"

Account::Account(std::string acc_name, double acc_balance)
    : name{acc_name}, balance{acc_balance} {}

bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    }
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    auto res {balance - amount};
    if (res >= 0) {
        balance = res;
        return true;
    }
    return false;
}

double Account::get_balance() const {
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "[Account: " << account.name << " : " << account.balance << "]";
    return os;
}
