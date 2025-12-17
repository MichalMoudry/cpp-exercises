#include <cctype>
#include <memory>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
//#include <set>
#include <string>

/*
We will be reading words from a text file provided for you.
The text file is named "words.txt" and contains the first few
paragraphs from the book, "The Wonderful Wizard of Oz", by
L. Frank Baum.

Part 1:
For part 1 of this challenge, you are to display each unique
word in the file and immediately following each word display
the number of time it occurs in the text file.

The words should be displayed in ascending order.

Here is a sample listing of the first few words:
Word      Count
========================
Aunt          5
Dorothy       8
Dorothy's     1
Em            5

Use a map with <string, int> Key/Value pairs


Part 2:
You are to display each unique word in the file and immediately
following each word display the line numbers in which that word
appears.

The words should be displayed in ascending order and the line
numbers for each word should also be displayed in ascending order.
If a word appears more than once on a line then the line number
should only appear only once.

A sample listing:
Word      Occurrences
=========================================
Aunt      [ 2 7 25 29 48 ]
Dorothy   [ 1 7 15 29 39 43 47 51 ]
Dorothy's [ 31 ]
Em        [ 2 7 25 30 48 ]

Use a map of <string, set<int>> Key/Value pairs.

Hint: consider using stringstream to process words
once you read in a line from the file.

Note: I have provided the basic shell for your program.
I have also provided the functions that display the maps
as well as the function that cleans the words read.
You should call the clean_string function for every word 
you read from the file.
*/

int main() {
    std::ifstream in_file {"./udemy/section20/challenge03/words.txt"};
    if (!in_file.is_open()) {
        std::cerr << "Problem opening file" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "The file was successfully read..." << std::endl;

    std::string line;
    std::unique_ptr<std::map<std::string, int>> word_count {
        std::make_unique<std::map<std::string, int>>()
    };
    while (std::getline(in_file, line)) {
        std::istringstream line_stream {line};
        std::string word;
        while (line_stream >> word) {
            if (!std::isalpha(word.back())) {
                word.resize(word.length() - 1);
            }
            if (word_count->find(word) == word_count->end()) {
                word_count->insert(std::make_pair(word, 1));
            }
            else {
                (*word_count)[word] += 1;
            }
        }
    }

    // Print out a table for the 1st part
    std::cout
        << std::setw(12) << std::left
        << "Word"
        << std::setw(14) << std::left
        << "Count" << std::endl;
    std::cout << "=========================" << std::endl;
    for (const auto& count : *word_count) {
        std::cout
            << std::setw(12) << std::left
            << count.first
            << std::setw(5) << std::right
            << count.second << std::endl;
    }

    return EXIT_SUCCESS;
}