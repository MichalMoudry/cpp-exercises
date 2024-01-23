#include <iostream>
#include <string>

namespace log_line {
    std::string message(std::string input) {
        int spaceIndex = input.find(" ");
        int length = input.length();
        return input.substr(spaceIndex + 1, (length - spaceIndex));
    }

    std::string log_level(const std::string& input) {
        std::basic_string<char>::size_type spaceIndex = input.find(' ');
        return input.substr(1, spaceIndex - 3);
    }

    std::string reformat(std::string input) {
        return message(input) + " (" + log_level(input) + ")";
    }
}

int main() {
    std::cout << log_line::message("[ERROR]: Invalid operation") << std::endl;
    std::cout << log_line::log_level("[ERROR]: Invalid operation") << std::endl;
    std::cout << log_line::reformat("[INFO]: Operation completed") << std::endl;
}
