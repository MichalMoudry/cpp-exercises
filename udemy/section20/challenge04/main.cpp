/*
A Palindrome is a string that reads the same backwards or forwards.
Examples:
- bob
- toot
- radar
- C++

An entire phrase can also be a palindrome, for example:
- A Toyota's a toyota
- A Santa at NASA
- A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!

All alpha characters are considered, and all others are omitted. Also, the
program is case insensitive.
*/

#include <cctype>
#include <ios>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>

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

bool is_palindrome(const std::string& str) {
    std::stack<char> chars = std::stack<char>();
    std::queue<char> queue = std::queue<char>();

    for (const auto c : str) {
        if (!std::isalpha(c) || c == ' ') {
            continue;
        }
        char lower = std::tolower(c);
        chars.push(lower);
        queue.push(lower);
    }

    char actual;
    char reverse;
    while (!queue.empty()) {
        actual = queue.front();
        reverse = chars.top();
        if (actual != reverse) {
            return false;
        }
        queue.pop();
        chars.pop();
    }

    return true;
}

int main() {
    std::vector<std::string> test_strings {
        "a",
        "aa",
        "aba",
        "abba",
        "abbcbba",
        "ab",
        "abc",
        "radar",
        "bob",
        "C++",
        "A Toyota's a toyota",
        "A Santa at NASA",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "pes",
        "tenet"
    };

    //std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }

    return 0;
}
