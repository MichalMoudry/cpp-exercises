#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person final {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string new_name, int new_age)
        : name{new_name}, age{new_age} {}
    bool operator<(const Person& rhs) const {
        return age < rhs.age;
    }
    bool operator==(const Person& rhs) const {
        return name == rhs.name && age == rhs.age;
    }
};

void find_test() {
    std::cout << "=====================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5};
    auto loc {std::find(std::begin(vec), std::end(vec), 1)};

    if (loc != std::end(vec)) {
        /* code */
    }
}

int main() {
    find_test();
    return 0;
}