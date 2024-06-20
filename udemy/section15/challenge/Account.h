#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

/// @brief A generic bank account.
class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);

private:
    static constexpr const char* def_name {"Unnamed account"};
    static constexpr double def_balance {0.0};

protected:
    std::string name;
    double balance;

public:
    Account(std::string acc_name = def_name, double acc_balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

#endif