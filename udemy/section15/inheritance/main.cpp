#include <iostream>

class Account {
public:
    double balance;
    std::string name;
    void deposit(double amount) {
        std::cout << "Account deposit called with: " << amount << std::endl;
    }

    void withdraw(double amount) {
        std::cout << "Account withdraw called with: " << amount << std::endl;
    }

    void display() {
        std::cout << name << " has balance of " << balance << std::endl;
    }

    Account() : name{"Account"}, balance{0.0} {
    }
    ~Account() {}
};

class SavingsAccount : public Account {
public:
    double interest_rate;
    void deposit(double amount) {
        std::cout << "Savings Account deposit called with: " << amount << std::endl;
    }

    void withdraw(double amount) {
        std::cout << "Savings Account withdraw called with: " << amount << std::endl;
    }

    SavingsAccount() : interest_rate{0.03} {}
    ~SavingsAccount() {}
};

int main() {
    Account normal_account {};
    normal_account.deposit(2'000.0);
    normal_account.withdraw(500.0);
    normal_account.display();
    std::cout << std::endl;

    Account* p_acc {new Account()};
    p_acc->deposit(1'000.0);
    p_acc->withdraw(500.0);
    p_acc->display();
    std::cout << std::endl;
    delete p_acc;

    SavingsAccount saving_account {};
    saving_account.deposit(2'000.0);
    saving_account.withdraw(500.0);
    saving_account.display();
    std::cout << std::endl;

    SavingsAccount* p_saving_account {new SavingsAccount()};
    p_saving_account->deposit(2'000.0);
    p_saving_account->withdraw(500.0);
    p_saving_account->display();
    std::cout << std::endl;
    return 0;
}