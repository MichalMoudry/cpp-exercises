#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void display(std::stack<T> stack) {
    size_t size = stack.size();
    std::cout << "[ ";
    while (!stack.empty()) {
        T item = stack.top();
        stack.pop();
        std::cout << item << " ";
    }
    std::cout << "] - size: " << size << std::endl;
}

int main() {
    std::stack<int> s = std::stack<int>(std::deque<int>{1, 2, 3, 4, 5});
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;

    display(s);
    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty()) {
        s.pop();
    }
    display(s);
}
