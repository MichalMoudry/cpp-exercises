#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SquareFunctor final {
    public:
    void operator()(int x) {
        std::cout << x * x << " ";
    }
};

template<typename T>
class Displayer final {
    public:
    void operator()(const T& data) {
        std::cout << data << " ";
    }
};

class Multiplier final {
    int num {};
    public:
    Multiplier(int n) : num(n) { }
    int operator()(int n) const {
        return n * num;
    }
};

void test1() {
    std::cout << "Test 1 ====================" << std::endl;
    SquareFunctor square;
    square(4); // square.operator()(4);

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);
    d2("Michal");
    std::cout << std::endl;
}

void test2() {
    std::cout << "\nTest 2 ====================" << std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};

    SquareFunctor square;
    std::for_each(vec1.begin(), vec1.end(), square);
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>{});
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>{});
    std::cout << std::endl;
}

void test3() {
    std::cout << "\nTest 3 ====================" << std::endl;
    Multiplier mult {100};
    Displayer<int> d1;

    std::vector<int> vec1 {1, 2, 3, 4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) {
        return x * 100;
    });
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    test1();
    test2();
    test3();
}
