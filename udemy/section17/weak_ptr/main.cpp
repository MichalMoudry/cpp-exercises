#include <iostream>
#include <memory>

class B;

class A final {
    std::shared_ptr<B> b_ptr;
public:
    void set_b(std::shared_ptr<B>& b) {
        b_ptr = b;
    }
    A() {
        std::cout << "A Constructor" << std::endl;
    }
    ~A() {
        std::cout << "A Destructor" << std::endl;
    }
};

class B final {
    std::weak_ptr<A> a_ptr;
public:
    void set_a(std::shared_ptr<A>& a) {
        a_ptr = a;
    }
    B() {
        std::cout << "B Constructor" << std::endl;
    }
    ~B() {
        std::cout << "B Destructor" << std::endl;
    }
};

int main() {
    auto a {std::make_shared<A>()};
    auto b {std::make_shared<B>()};
    a->set_b(b);
    b->set_a(a);

    return 0;
}