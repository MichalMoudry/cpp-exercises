#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* const argv[]) {
    std::ofstream out_file {
        "./udemy/section19/file_write/output.txt"
        //std::ios::app
    };
    std::ifstream in_file {"./udemy/section19/file_write/poem.txt"};
    if (!in_file) {
        std::cerr << "Error opening an input file" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opeing an output file" << std::endl;
        return 1;
    }

    /*std::string line;
    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);
    out_file << line << std::endl;*/

    std::string line;
    while (std::getline(in_file, line)) {
        out_file << line << std::endl;
    }
    std::cout << "File copied..." << std::endl;

    in_file.close();
    out_file.close();
    return 0;
}
