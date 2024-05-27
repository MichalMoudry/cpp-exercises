#include <iostream>

class Shallow {
private:
    int* data;
public:
    void set_data_value(int d) {
        *data = d;
    }
    int get_data() {
        return *data;
    }

    Shallow(int d) {
        data = new int;
        *data = d;
    }
    Shallow(const Shallow& src) : data(src.data) {
        std::cout << "Copy ctor - shallow copy" << std::endl;
    }
    ~Shallow() {
        delete data;
        std::cout << "Destructor freeing data\n";
    }
};

void display_shallow(Shallow s) {
    std::cout << s.get_data() << std::endl;
}

int main() {
    Shallow obj1 {100};
    display_shallow(obj1);

    Shallow obj2 {obj1};
    return 0;
}