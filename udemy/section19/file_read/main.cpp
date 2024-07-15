#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::ifstream in_file {"./udemy/section19/file_read/poem.txt"};

    if (!in_file.is_open()) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    // Formated input
    /*std::string line {};
    while (std::getline(in_file, line)) {
        std::cout << line << std::endl;
    }*/

    // Unformatted input
    char c;
    while (in_file.get(c)) {
        std::cout << c;
    }
    std::cout << std::endl;

    in_file.close();
    return 0;
}
