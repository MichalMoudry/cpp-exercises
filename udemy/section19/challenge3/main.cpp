#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file {"./udemy/section19/challenge3/romeoandjuliet.txt"};
    std::ofstream out_file {"./udemy/section19/challenge3/output.txt"};
    if (!in_file) {
        std::cerr << "Error opening an input file" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opeing an output file" << std::endl;
        return 1;
    }

    std::string line;
    uint line_number {1};
    while (std::getline(in_file, line)) {
        if (line.length() != 0) {
            out_file << line_number << ". " << line << line.length() << std::endl;
        }
        line_number += 1;
    }
    std::cout << "File copied..." << std::endl;

    in_file.close();
    out_file.close();
    return 0;
}