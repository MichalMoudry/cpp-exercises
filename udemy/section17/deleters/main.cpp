#include <iostream>
#include <memory>

class Test final {
private:
    int data;
public:
    Test() : data{0} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }
    Test(int new_data) : data{new_data} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }
    int get_data() const { return data; }
    ~Test() {
        std::cout << "\tTest destructor (" << data << ")" << std::endl;
    }
};

void my_deleter(Test* ptr) {
    std::cout << "\tUsing custom deleter function" << std::endl;
    delete ptr;
}

int main(int argc, char const *argv[]) {
    {
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter};
    }

    std::cout << "======================" << std::endl;

    {
        std::shared_ptr<Test> ptr2 {
            new Test{101},
            [] (Test* ptr) {
                std::cout << "\tUsing custom lambda deleter" << std::endl;
                delete ptr;
            }
        };
    }
    return 0;
}
