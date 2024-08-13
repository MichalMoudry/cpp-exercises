#include <iostream>
#include <string>
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
    std::cout << "=====================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test() {
    std::cout << "=====================" << std::endl;
    std::vector<int> vec1 {1, 3, 5, 7, 9, 1, 3, 13, 19, 5};

    auto all_of {
        std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 10; })
    };
    if (all_of) {
        std::cout << "All the elements are > 10" << std::endl;
    } else {
        std::cout << "Not all elements are > 10" << std::endl;
    }

    all_of = std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 20; });
    if (all_of) {
        std::cout << "All the elements are > 20" << std::endl;
    } else {
        std::cout << "Not all elements are > 20" << std::endl;
    }
}

void string_transform_test() {
    std::cout << "=====================" << std::endl;

    std::string str {"This is a test"};
    std::cout << "Before transform: " << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << "After transform: " << str << std::endl;
}

int main() {
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
    return 0;
}