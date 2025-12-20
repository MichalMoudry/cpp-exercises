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

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& str) {
    return false;
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
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!"
    };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        //std::cout << std::setw(150) << std::left << is_palindrome(s) << "s" << std::endl;
    }

    return 0;
}
