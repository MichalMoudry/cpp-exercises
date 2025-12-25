#include <iostream>
#include <string>
#include <queue>

class Person final {
    std::string name;
    int age;

    public:
    Person() : name("Unknown"), age(0) { }

    Person(std::string name, int age) : name(name), age(age) { }

    bool operator<(const Person& other) const {
        return this->age < other.age;
        // return this->name < other.name;
    }

    bool operator==(const Person& other) const {
        return this->name == other.name && this->age == other.age;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Person {name='" << person.name << "', age=" << person.age << "}";
    return os;
}

template<typename T>
void display(std::priority_queue<T> queue) {
    auto size = queue.size();
    std::cout << "[ ";
    while (!queue.empty()) {
        T top = queue.top();
        queue.pop();
        std::cout << top << " ";
    }
    std::cout << "] - size: " << size << std::endl;
}

int main() {
    std::priority_queue<int> pq;
    for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7}) {
        pq.push(i);
    }
    display(pq);

    pq.pop();
    display(pq);

    std::priority_queue<Person> q;
    q.emplace("A", 100);
    q.emplace("B", 50);
    q.emplace("C", 25);
    display(q);
}
