#include <iostream>

class Deep {
private:
    int* data;
public:
    void set_data_value(int d) {
        *data = d;
    }
    int get_data() {
        return *data;
    }

    Deep(int d) {
        data = new int;
        *data = d;
    }

    Deep(const Deep& src) : Deep {*src.data} {
        std::cout << "Copy ctor - deep copy\n";
    }

    ~Deep() {
        delete data;
        std::cout << "Destructor freeing data\n";
    }
};

void display_deep(Deep d) {
    std::cout << d.get_data() << std::endl;
    d.set_data_value(300);
    std::cout << d.get_data() << std::endl;
}

int main() {
    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 {obj1};
    display_deep(obj2);
    return 0;
}