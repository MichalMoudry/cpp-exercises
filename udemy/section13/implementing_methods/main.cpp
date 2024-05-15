#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string name;
    double balance;

public:
    void set_balance(double val) { balance = val; }
    double get_balance() { return balance; }

    void set_name(string n);
    string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

void Account::set_name(string n) { name = n; }
string Account::get_name() { return name; }

bool Account::deposit(double amount) {
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    return false;
}

int main() {
    Account test_account;
    test_account.set_name("Test account");
    test_account.set_balance(1'000.0);

    if (test_account.deposit(200.0)) {
        cout << "Deposit OK" << endl;
    }

    if (test_account.withdraw(500.0)) {
        cout << "Withdrawal OK" << endl;
    } else {
        printf("Insufficient funds\n");
    }

    if (test_account.withdraw(1'500.0)) {
        printf("Withdrawal OK\n");
    } else {
        printf("Insufficient funds\n");
    }
}