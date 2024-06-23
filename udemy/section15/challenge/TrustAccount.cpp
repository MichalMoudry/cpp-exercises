#include "TrustAccount.h"

TrustAccount::TrustAccount(
    std::string acc_name,
    double acc_balance,
    double acc_interest_rate
) : Account{acc_name, acc_balance}, interest_rate{acc_interest_rate} {}

bool TrustAccount::deposit(double amount) {
    if (amount >= 5'000) {
        balance += amount + 50;
        return true;
    }
    else if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool TrustAccount::withdraw(double amount) {
    auto limit {(balance/100) * 20};
    if (withdrawals >= 3 || amount >= limit || balance - amount < 0) {
        return false;
    }
    balance -= amount;
    withdrawals += 1;
    return true;
}

std::ostream& operator<<(
    std::ostream& os,
    const TrustAccount& account) {
    os << "[Trust account: "
        << account.name << " : "
        << account.balance << ", "
        << account.interest_rate << "%, "
        << "withdrawals: " << account.withdrawals
        << "]";
    return os;
}