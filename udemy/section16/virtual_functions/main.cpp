#include <iostream>
#include <memory>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object\n";
    }
};

class Derived : public Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Derived class object\n";
    }
};

void greetings(const Base& obj) {
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main() {
    Base base {};
    base.say_hello();
    greetings(base);
    std::cout << std::endl;

    Derived derived {};
    derived.say_hello();
    greetings(derived);
    std::cout << std::endl;

    Base* ptr {new Derived()};
    ptr->say_hello();
    std::cout << std::endl;

    std::unique_ptr<Base> ptr1 {std::make_unique<Derived>()};
    ptr1->say_hello();

    delete ptr;
    return 0;
}