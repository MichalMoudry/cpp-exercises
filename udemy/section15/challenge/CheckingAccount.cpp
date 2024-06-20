#include "CheckingAccount.h"

bool CheckingAccount::withdraw(double amount) {
    auto res {balance - amount - withdrawal_fee};
    if (res >= 0) {
        balance = res;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const CheckingAccount& account) {
    os
        << "[Checking account: "
        << account.name << " : "
        << account.balance << "]";
    return os;
}