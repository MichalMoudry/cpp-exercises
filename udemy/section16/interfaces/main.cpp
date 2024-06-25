#include <iostream>

class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw\n";
    }
    virtual ~Account() {}
};

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account display";
    return os;
}

class Checking final : public Account {
    friend std::ostream& operator<<(std::ostream& os, const Checking& account);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw\n";
    }
    virtual ~Checking() {}
};

std::ostream& operator<<(std::ostream& os, const Checking& account) {
    os << "Checking display";
    return os;
}

class Savings final : public Account {
    friend std::ostream& operator<<(std::ostream& os, const Savings& account);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw\n";
    }
    virtual ~Savings() {}
};

std::ostream& operator<<(std::ostream& os, const Savings& account) {
    os << "Savings display";
    return os;
}

int main() {
    Account* p1 {new Account()};
    std::cout << *p1 << std::endl;

    Account* p2 {new Checking()};
    std::cout << *p2 << std::endl;

    delete p1;
    delete p2;

    /*Account a;
    std::cout << a << std::endl;

    Checking c;
    std::cout << c << std::endl;

    Savings s;
    std::cout << s << std::endl;*/
    return 0;
}