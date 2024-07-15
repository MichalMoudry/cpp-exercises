#include <iostream>
#include <fstream>

int main(int argc, char* const argv[]) {
    std::ifstream in_file;
    in_file.open("./udemy/section19/challenge2/romeoandjuliet.txt");

    if (!in_file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string requested_word;
    std::cout << "Find a word: ";
    std::getline(std::cin, requested_word);

    if (requested_word == "") {
        std::cerr << "Enter a valid input..." << std::endl;
        return 1;
    }

    std::string word;
    uint ref_count {0};
    uint word_count {0};
    while (in_file >> word) {
        if (word.find(requested_word) != std::string::npos) {
            ref_count += 1;
        }
        word_count += 1;
    }

    std::cout << word_count << " words were searched..." << std::endl;
    std::cout
        << "The substring " << requested_word
        << " were found " << ref_count << " times"
        << std::endl;

    return 0;
}
