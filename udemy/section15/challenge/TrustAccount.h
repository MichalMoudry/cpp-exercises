#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Account.h"

class TrustAccount : public Account {
    friend std::ostream& operator<<(
        std::ostream& os,
        const TrustAccount& account
    );

private:
    ushort withdrawals;
protected:
    double interest_rate;

public:
    TrustAccount(
        std::string acc_name = "Unnamed savings account",
        double acc_balance = 0.0,
        double acc_interest_rate = 0.0
    );
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif