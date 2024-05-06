#include <iostream>
#include <string>

std::string reverse_string(const std::string& str) {
    std::string reversed;

    reversed = str;
    size_t max_str_size {str.size() - 1};
    int start_index {0};
    for (int i = max_str_size; i >= 0; i--) {
        reversed.at(start_index) = str[i];
        start_index += 1;
    }

    return reversed;
}

int main() {
    std::string input {"Hello, World!"};
    std::string reversed {reverse_string(input)};

    std::cout
        << "Input: " << input << std::endl
        << "Reversed: " << reversed << std::endl;
    return 0;
}