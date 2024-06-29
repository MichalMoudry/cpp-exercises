#include <iostream>
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
    auto p1 = std::make_shared<Test>(1'000);
    std::cout << p1.use_count() << std::endl;
    return 0;
}