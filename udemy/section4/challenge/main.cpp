#include <iostream>

int main() {
    std::string favourite_number;
    std::cout << "Enter your favourite number between 1 and 100: ";
    std::cin >> favourite_number;

    char* p;
    auto converted = std::strtol(favourite_number.c_str(), &p, 10);
    if (*p) {
        std::cout << "Your input was not a value!" << std::endl;
    }
    else {
        std::cout << "Amazing!! That's my favourite number too!" << std::endl;
        std::cout << "No really!!, " << converted << " is my favourite number!";
    }
    return 0;
}
