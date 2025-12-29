#include <iostream>

int global_x = 100;

void test1() {
    std::cout << "\nTest 1 ====================" << std::endl;
    int local_x {100};
    auto l = [local_x]() {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

void test2() {
    std::cout << "\nTest 2 ====================" << std::endl;
    int x {100};
    auto l = [x]() mutable { 
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;
    l();
    std::cout << x << std::endl;
}

void test3() {
    std::cout << "\nTest 3 ====================" << std::endl;
    int x {100};
    auto l = [&x]() mutable {
        x += 100;
        std::cout << "inside lambda = " << x << std::endl;
    };
    l();
    std::cout << "outside lambda = " << x << std::endl;
}

void test4() {
    std::cout << "\nTest 4 ====================" << std::endl;
    int x {100}, y {200}, z {300};
    auto l = [=]() mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();

    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

void test5() {
    std::cout << "\nTest 5 ====================" << std::endl;
    int x {100}, y {200}, z {300};
    auto l = [&]() {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    std::cout << std::endl;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test6() {
    std::cout << "\nTest 6 ====================" << std::endl;
    int x {100}, y {200}, z {300};
    auto l = [=, &y]() mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    std::cout << std::endl;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

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

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
