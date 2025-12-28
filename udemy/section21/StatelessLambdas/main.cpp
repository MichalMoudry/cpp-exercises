#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Person final {
public:
    friend std::ostream& operator<<(std::ostream&, const Person&);

    Person(std::string name, int age) : name(name), age(age) { }
    Person(const Person& other) : name(other.name), age(other.age) { }

    std::string get_name() const { return name; }

    int get_age() const { return age; }

    void set_name(std::string name) {
        this->name = name;
    }

    void set_age(int age) {
        this->age = age;
    }

private:
    std::string name;
    int age;
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Person {name='" << person.name << "', age=" << person.age << "}";
    return os;
}

void test1() {
    std::cout << "Test 1 ====================" << std::endl;
    []() { std::cout << "Hi" << std::endl; }();
    [](int x) { std::cout << x << std::endl; }(100);
    [](int x, int y) { std::cout << x + y << std::endl; }(100, 200);
}

void test2() {
    std::cout << "\nTest 2 ====================" << std::endl;
    int num1 {100}, num2 {100};

    auto l2 = [](int x, int y) {
        std::cout << x + y << std::endl;
    };
    l2(10, 20);
    l2(num1, num2);

    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    auto l3 = [](int& x, int& y) {
        std::cout << "x = " << x << ", y = " << y << std::endl;
        x = 1'000;
        y = 2'000;
    };
    l3(num1, num2);
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
}

void test3() {
    std::cout << "\nTest 3 ====================" << std::endl;
    Person stooge {"Larry", 30};
    std::cout << stooge << std::endl;

    auto l1 = [](Person p) {
        std::cout << p << std::endl;
    };
    l1(stooge);

    auto l2 = [](const Person& p) {
        std::cout << p << std::endl;
    };
    l2(stooge);

    auto l3 = [](Person& p) {
        p.set_name("Michal");
        p.set_age(27);
        std::cout << p << std::endl;
    };
    l3(stooge);
    std::cout << stooge << std::endl;
}

void filter_vector(const std::vector<int>& vec, std::function<bool(int)> func) {
    std::cout << "[ ";
    for (int i : vec) {
        if (func(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "]" << std::endl;
}

void test4() {
    std::cout << "\nTest 4 ====================" << std::endl;
    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 80, 100};
    filter_vector(nums, [](int x) { return x > 50; });
    filter_vector(nums, [](int x) { return x <= 30; });
    filter_vector(nums, [](int x) { return x >= 30 && x <= 60; });
}

void test5() {
    std::cout << "\nTest 4 ====================" << std::endl;
    std::vector<Person> stooges {
        {"Larry", 20},
        {"Moe", 30},
        {"Curly", 40}
    };

    auto start = stooges.begin();
    auto end = stooges.end();
    std::sort(
        start,
        end,
        [](const Person& p1, const Person& p2) {
            return p1.get_name() < p2.get_name();
        }
    );
    std::for_each(start, end, [](const Person& person) {
        std::cout << person << std::endl;
    });
    std::cout << std::endl;

    std::sort(
        start,
        end,
        [](const Person& p1, const Person& p2) {
            return p1.get_age() < p2.get_age();
        }
    );
    std::for_each(start, end, [](const Person& person) {
        std::cout << person << std::endl;
    });
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
