#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class CheckingAccount : public Account {
friend std::ostream& operator<<(std::ostream& os, const CheckingAccount& account);
private:
    static constexpr double withdrawal_fee = 1.50;
public:
    CheckingAccount() {}
    CheckingAccount(std::string acc_name) : Account{acc_name} {}
    bool withdraw(double amount);
};

#endif