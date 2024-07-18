#include <iostream>
#include <string>

template<typename T>
class Item final {
private:
    std::string name;
    T value;
public:
    Item(std::string init_name, T val) : name{init_name}, value{val} {}
    std::string get_name() const {
        return name;
    }
    T get_value() const {
        return value
    }
};

template<typename T1, typename T2>
struct Pair final {
    T1 first;
    T2 second;
};

int main() {
    return 0;
}