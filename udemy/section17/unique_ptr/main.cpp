#include <iostream>
#include <utility>
#include <vector>
#include <memory>

class Test final {
private:
    int data;
public:
    Test() : data{0} {
        std::cout << "Test ctor (" << data << ")\n";
    }

    Test(int inpt) : data{inpt} {
        std::cout << "Test ctor (" << data << ")\n";
    }

    int get_data() const {
        return data;
    }

    ~Test() {
        std::cout << "Test destructor (" << data << ")\n";
    }
};

int main() {
    /*Test* t1 {new Test(1'000)};
    delete t1;*/

    std::unique_ptr<Test> t1 {new Test(100)};
    auto t2 = std::make_unique<Test>(1'000);

    std::unique_ptr<Test> t3;
    t3 = std::move(t1);
    if (!t1) {
        std::cout << "t1 is nullptr\n";
    }

    return 0;
}