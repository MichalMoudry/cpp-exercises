#include <iostream>

class Base {
private:
    int value;
public:
    Base() : value{0} {
        std::cout << "Base no-args ctor" << std::endl;
    }

    Base(int x) : value{x} {
        std::cout << "int Base ctor" << std::endl;
    }

    Base(const Base& other) : value{other.value} {
        std::cout << "Base copy ctor" << std::endl;
    }

    Base& operator=(const Base& rhs) {
        std::cout << "Base operator=" << std::endl;
        if (this == &rhs) {
            return *this;
        }
        value = rhs.value;
        return *this;
    }

    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived() : Base{} {
        std::cout << "Derived no-args ctor" << std::endl;
    }

    Derived(int x) : Base{x}, doubled_value{x * 2} {
        std::cout << "int Derived ctor" << std::endl;
    }

    Derived(const Derived& other)
        : Base{other}, doubled_value{other.doubled_value} {
        std::cout << "Derived copy ctor" << std::endl;
    }

    Derived& operator=(const Derived& rhs) {
        std::cout << "Derived operator=" << std::endl;
        if (this == &rhs) {
            return *this;
        }
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }

    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

class Test {
private:
    int val;
public:
    Test() : val{0} {
    }
    Test(int x) : val{x} {
    }
    Test(const Test& src) : val{src.val} {
    }

    int get_val() {
        return val;
    }
    void add_val(int x) {
        val += x;
    }
};

int main() {
    //Base b {100}; // overloaded constructor
    //Base b1 {b}; // copy constructor
    //b = b1; // copy assignment

    Derived d {100};
    Derived d1 {d};
    d = d1;

    Test test1 {100};
    Test test2;
    test2 = test1;
    std::cout << test1.get_val() << std::endl;
    test2.add_val(10);
    std::cout << test2.get_val() << std::endl;
    return 0;
}