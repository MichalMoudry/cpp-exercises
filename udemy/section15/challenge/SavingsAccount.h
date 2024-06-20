#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"

class SavingsAccount : public Account {
    friend std::ostream& operator<<(
        std::ostream& os,
        const SavingsAccount& sav_account
    );

protected:
    double interest_rate;

public:
    SavingsAccount(
        std::string acc_name = "Unnamed savings account",
        double acc_balance = 0.0,
        double acc_interest_rate = 0.0
    );
    bool deposit(double amount);
};

#endif