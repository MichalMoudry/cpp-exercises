#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

bool is_palindrome(const std::string& str) {
    if (str == "") {
        return false;
    }
    std::deque<char> reverse;
    for (auto c : str) {
        if (std::isalpha(c)) {
            reverse.push_back(std::toupper(c));
        }
    }

    auto len {reverse.size()};
    char c1;
    char c2;
    while (len > 1) {
        c1 = reverse.front();
        c2 = reverse.back();
        if (c1 != c2) {
            return false;
        }
        reverse.pop_front();
        reverse.pop_back();
        len -= 2;
    }
    /*auto len {str.length()};
    std::vector<char> current;
    std::deque<char> reverse (len);

    char current_char;
    for (size_t i = 0; i < len; i++) {
        current_char = std::toupper(str[i]);
        if (std::isalpha(current_char)) {
            current.push_back(current_char);
            reverse.push_front(current_char);
        }
    }

    for (size_t i = 0; i < current.size(); i++) {
        if (reverse[i] != current[i]) {
            return false;
        }
    }*/
 
    return true;
}

int main() {
    std::cout << std::boolalpha;

    std::string words[] {
        "bob",
        "",
        "toot",
        "radar",
        "test",
        "A Santa at NASA",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "A Toyota's a toyota",
        "ttt",
        "Hello",
        "aba"
    };

    for (const std::string& str : words) {
        std::cout << "Is " << str << " a palindrome? " << is_palindrome(str) << std::endl;
    }
    return 0;
}