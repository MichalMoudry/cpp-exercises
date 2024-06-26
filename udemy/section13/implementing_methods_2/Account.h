#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account {
private:
    std::string name;
    double balance;

public:
    void set_balance(double val) { balance = val; }
    double get_balance() { return balance; }

    void set_name(std::string n);
    std::string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif