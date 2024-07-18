#include <iostream>
#include <string>

template<typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T1, typename T2>
void func(T1 a, T2 b, std::string&& separator = " ") {
    std::cout << a << separator << b << std::endl;
}

struct Person final {
    std::string name;
    int age;
    bool operator<(const Person& rhs) const {
        return age < rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name;
    return os;
}

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    Person p1 {"Curly", 50};
    Person p2 {"Moe", 30};
    Person p3 {min(p1, p2)};
    std::cout << p3.name << " is younger" << std::endl;
    func(p1, p3);

    std::cout << min<int>(2, 3) << std::endl;
    std::cout << min(2, 3) << std::endl;
    std::cout << min('A', 'B') << std::endl;
    std::cout << min(12.5, 9.2) << std::endl;

    func<int, int>(10, 20);
    func(10, 20);
    func('A', 12.4);

    int x {100};
    int y {200};
    func(x, y, ", ");
    swap(x, y);
    func(x, y, ", ");
    return 0;
}