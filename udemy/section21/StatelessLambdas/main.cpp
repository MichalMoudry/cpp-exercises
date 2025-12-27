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

void test4() {
    std::cout << "\nTest 4 ====================" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
