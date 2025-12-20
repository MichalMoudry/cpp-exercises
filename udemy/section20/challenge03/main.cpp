#include <cctype>
#include <memory>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <utility>

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

// Resets a file stream and sets a new position (0 by default).
void reset_stream(std::ifstream&, int position = 0);

std::string clean_string(const std::string& str);

int main() {
    std::ifstream in_file {"./udemy/section20/challenge03/words.txt"};
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "The file was successfully read..." << std::endl;

    auto word_count {
        std::make_unique<std::map<std::string, int>>()
    };
    std::string line;
    std::string word;
    while (std::getline(in_file, line)) {
        std::istringstream line_stream {line};
        while (line_stream >> word) {
            word = clean_string(word);
            (*word_count)[word] += 1;
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

    // === 2nd part
    std::cout << "\n\n===> Part 2" << std::endl;
    reset_stream(in_file);

    auto unique_words {
        std::make_unique<std::map<std::string, std::set<int>>>()
    };
    int line_number = 0;
    while (std::getline(in_file, line)) {
        line_number += 1;
        std::istringstream line_stream {line};
        while (line_stream >> word) {
            word = clean_string(word);
            (*unique_words)[word].insert(line_number);
        }
    }

    for (const auto& item : *unique_words) {
        std::cout << std::setw(13) << std::left << item.first << "[ ";
        for (const auto& line : item.second) {
            std::cout << line << " ";
        }
        std::cout << "]" << std::endl;
    }

    in_file.close();
    return EXIT_SUCCESS;
}

void reset_stream(std::ifstream& stream, int position) {
    stream.clear();
    stream.seekg(position);
}

std::string clean_string(const std::string& str) {
    std::string result;
    for (const char c : str) {
        if (c == '.' || c == ',' || c == ';' || c == ':') {
            continue;
        }
        result += c;
    }
    return result;
}
