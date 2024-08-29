#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>

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
*/

int main() {
    std::ifstream in_file {"./udemy/section20/challenge3/words.txt"};
    if (!in_file.is_open()) {
        std::cerr << "Problem opening file" << std::endl;
        return;
    }
    return 0;
}