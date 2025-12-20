#include <cstddef>
#include <queue>
#include <iostream>

template <typename T>
void display(std::queue<T> queue) {
    std::size_t size = queue.size();
    std::cout << "[ ";
    while (!queue.empty()) {
        T item = queue.front();
        queue.pop();
        std:: cout << item << " ";
    }
    std::cout << "] - size: " << size << std::endl;
}

template <typename T>
void display_front_back(const std::queue<T>& queue) {
    std::cout << "\tFront: " << queue.front() << std::endl;
    std::cout << "\tBack: " << queue.back() << std::endl;
}

int main() {
    std::queue<int> q;
    for (int i : {1, 2, 3, 4, 5}) {
        q.push(i);
    }
    display(q);
    display_front_back(q);

    q.push(100);
    display(q);
    display_front_back(q);

    q.front() = 5;
    q.back() = 5'000;
    display(q);
    display_front_back(q);
}
