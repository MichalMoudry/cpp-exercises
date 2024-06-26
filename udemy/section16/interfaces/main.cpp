#include <iostream>

class IPrintable {
    friend std::ostream& operator<<(std::ostream& os, const IPrintable& printable);
public:
    virtual void print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const IPrintable& printable) {
    printable.print(os);
    return os;
}

class Account: public IPrintable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw\n";
    }
    virtual void print(std::ostream& os) const override {
        os << "Account display";
    }
    virtual ~Account() {}
};

class Checking final : public Account {
public:
    virtual void withdraw(double amount) override {
        std::cout << "In Checking::withdraw\n";
    }
    virtual void print(std::ostream& os) const override {
        os << "Checking display";
    }
    virtual ~Checking() {}
};

class Savings final : public Account {
public:
    virtual void withdraw(double amount) override {
        std::cout << "In Savings::withdraw\n";
    }
    virtual void print(std::ostream& os) const override {
        os << "Account display";
    }
    virtual ~Savings() {}
};

class Dog final : public IPrintable {
public:
    virtual void print(std::ostream& os) const override {
        os << "Woof woof";
    }
};

void print(const IPrintable& printable) {
    std::cout << printable << std::endl;
}

int main() {
    Account* p1 {new Account()};
    std::cout << *p1 << std::endl;

    Account* p2 {new Checking()};
    std::cout << *p2 << std::endl;

    Dog* dog {new Dog()};
    std::cout << *dog << std::endl;
    print(*dog);

    delete p1;
    delete p2;
    delete dog;

    /*Account a;
    std::cout << a << std::endl;

    Checking c;
    std::cout << c << std::endl;

    Savings s;
    std::cout << s << std::endl;*/
    return 0;
}