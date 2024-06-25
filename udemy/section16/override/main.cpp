#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I am a Base class object\n";
    }
    virtual ~Base() {}
};

class Derived final: public Base {
public:
    virtual void say_hello() const override {
        std::cout << "Hello - I am a Derived class object\n";
    }
    virtual ~Derived() {}
};

int main() {
    Base* pt1 {new Base()};
    pt1->say_hello();

    Derived* pt2 {new Derived()};
    pt2->say_hello();

    Base* pt3 {new Derived()};
    pt3->say_hello();
    return 0;
}