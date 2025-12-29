#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

void test1() {
    std::cout << "Test 1 ====================" << std::endl;
    std::vector<int> nums {10, 20, 30, 40, 50};

    std::for_each(nums.begin(), nums.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

void test2() {
    std::cout << "\nTest 2 ====================" << std::endl;

    struct Point {
        int x;
        int y;
    };

    Point pt1 {1, 2};
    Point pt2 {4, 3};
    Point pt3 {3, 5};
    Point pt4 {3, 1};

    std::vector<Point> triangle1 {pt1, pt2, pt3};
    std::vector<Point> triangle2 {pt2, pt3, pt1};
    std::vector<Point> triangle3 {pt1, pt2, pt4};

    bool is_permutation = std::is_permutation(
        triangle1.begin(),
        triangle1.end(),
        triangle2.begin(),
        [](Point p1, Point p2) {
            return p1.x == p2.x && p1.y == p2.y;
        }
    );
    if (is_permutation) {
        std::cout << "Triangle1 and Triangle2 are equal!" << std::endl;
    }
    else {
        std::cout << "Triangle1 and Triangle2 aren't equal!" << std::endl;
    }

    bool is_permutation_2 = std::is_permutation(
        triangle1.begin(),
        triangle1.end(),
        triangle3.begin(),
        [](Point lhs, Point rhs) {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }
    );
    if (is_permutation_2) {
        std::cout << "Triangle1 and Triangle3 are equal!" << std::endl;
    }
    else {
        std::cout << "Triangle1 and Triangle3 aren't equal!" << std::endl;
    }
}

void test3() {
    std::cout << "\nTest 3 ====================" << std::endl;
    std::array<int, 5> test_scores {93, 88, 75, 68, 65};
    int bonus_points = 5;

    std::transform(
        test_scores.begin(),
        test_scores.end(),
        test_scores.begin(),
        [bonus_points](int score) {
            return score + bonus_points;
        }
    );

    for (int score : test_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
}

void test4() {
    std::cout << "\nTest 4 ====================" << std::endl;
    std::vector<int> nums {1, 2, 3, 4, 5};
    nums.erase(std::remove_if(nums.begin(), nums.end(), [](int i) {
        return i % 2 == 0;
    }), nums.end());

    for (int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
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

void test5() {
    std::cout << "\nTest 5 ====================" << std::endl;

    Person person1 {"Larry", 20};
    Person person2 {"Moe", 30};
    Person person3 {"Curly", 40};

    std::array<Person, 3> people {person1, person2, person3};
    std::sort(people.begin(), people.end(), [](const Person& lhs, const Person& rhs) {
        return lhs.get_name() < rhs.get_name();
    });

    for (const Person& person : people) {
        std::cout << person << std::endl;
    }
}

bool in_between(const std::vector<int>& nums, int start_val, int end_val) {
    return std::all_of(nums.begin(), nums.end(), [start_val, end_val](int val) {
        return val >= start_val && val <= end_val;
    });
}

void test6() {
    std::cout << "\nTest 6 ====================" << std::endl;
    std::cout << std::boolalpha;

    std::vector<int> nums(10);
    std::iota(nums.begin(), nums.end(), 1);
    for (int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << in_between(nums, 50, 60) << std::endl; // false
    std::cout << in_between(nums, 1, 10) << std::endl; // true
}

class PasswordValidator final {
private:
    const char restricted_symbol {'$'};

public:
    bool is_valid(std::string pass) const {
        return std::all_of(pass.begin(), pass.end(), [this](char c) {
            return c != restricted_symbol;
        });
    }
};

void test7() {
    std::cout << "\nTest 7 ====================" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}
