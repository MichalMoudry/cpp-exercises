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
    auto end {std::end(vec)};
    auto loc {std::find(std::begin(vec), end, 1)};

    if (loc != end) {
        std::cout << "Found the number: " << *loc << std::endl;
    } else {
        std::cout << "Couldn't find the number" << std::endl;
    }

    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };
    auto players_end {players.end()};
    auto loc1 {
        std::find(players.begin(), players_end, Person {"Moe", 20})
    };
    if (loc1 != players_end) {
        std::cout << "Found Moe" << std::endl;
    } else {
        std::cout << "Moe not found" << std::endl;
    }
}

void count_test() {
    std::cout << "=====================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};

    int num {
        static_cast<int>(std::count(vec.begin(), vec.end(), 1))
    };
    std::cout << num << " occurrences found" << std::endl;
}

void count_if_test() {
    std::cout << "=====================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1, 100};
    auto beginning {vec.begin()};
    auto end {vec.end()};

    int num = std::count_if(
        beginning,
        end,
        [](int x) { return x % 2 == 0; }
    );
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(
        beginning,
        end,
        [](int x) { return x % 2 != 0; }
    );
    std::cout << num << " odd numbers found" << std::endl;

    num = std::count_if(
        beginning,
        end,
        [](int x) { return x >= 5; }
    );
    std::cout << num << " are greater or equal than 5" << std::endl;
}

void replace_test() {

}

void all_of_test() {

}

int main() {
    find_test();
    count_test();
    count_if_test();
    return 0;
}