#include <iostream>
#include <string>
#include <vector>

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
        return value;
    }
};

template<typename T1, typename T2>
struct Pair final {
    T1 first;
    T2 second;
};

int main() {
    Item<int> item1 {"Michal", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2 {"Michal", "Test"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    Item<Item<std::string>> item3 {"Michal", {"test 1", "test 2"}};
    std::cout << item3.get_name() << " "
        << item3.get_value().get_name() << " "
        << item3.get_value().get_value()
        << std::endl;

    std::cout << "----------------------" << std::endl;

    std::vector<Item<double>> vec {};
    vec.push_back(Item<double>{"Larry", 100.0});
    vec.push_back(Item<double>{"Moe", 200.0});
    vec.push_back(Item<double>{"Curly", 300.0});

    for (const auto& item : vec) {
        std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    Pair<std::string, int> p1 {"Michal", 100};
    Pair<int, double> p2 {124, 13.6};
    std::cout << p1.first << ", " << p1.second << std::endl;
    std::cout << p2.first << ", " << p2.second << std::endl;
    return 0;
}