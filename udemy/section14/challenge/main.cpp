#include "my_string.h"
#include <iostream>

/*
Overload the following operators in the provided MyString class.
Two versions:
    - Overload the operators using member functions
    - Overload the same operators using non-member functions

Here is a list of the operators:
- unary minus (-) : returns the lowercase version of the objects string
- == : returns true if strings are equal
- !=
- < : returns true if the lhs string is lexically less than the rhs string
- >
- + : concatenantion
- += : concatenate the rhs string to the lhs string and store the result in lhs object
- * : repeat; results in a string that is copied n times
    s2 = "abc"
    s1 = s2 * 3
    s1 will result in "abcabcabc"
- *= : repeat the string on the lhs n times and store the result back in the lhs object
    s1 = "abc"
    s1 *= 3
    s1 will result in "abcabcabc"
*/

int main() {
    MyString test1 {};
    test1.display();
    MyString test2 {"TeSt 2"};
    test2.display();
    MyString test3 {"abc"};
    test3.display();
    MyString test4 {"Test 4"};
    test4.display();

    std::cout << "\nUnary minus op:\n";
    (-test2).display();
    test2.display();

    std::cout << "\nEquality op:\n";
    std::cout << (test1 == test2 ? "true" : "false") << std::endl;
    std::cout << (test2 == test2 ? "true" : "false") << std::endl;
    std::cout << (test2 == test4 ? "true" : "false") << std::endl;

    std::cout << "\nInquality op:\n";
    std::cout << (test1 != test2 ? "true" : "false") << std::endl;
    std::cout << (test2 != test2 ? "true" : "false") << std::endl;
    std::cout << (test2 != test4 ? "true" : "false") << std::endl;

    std::cout << "\nConcatenantion:\n";
    (test4 + test3).display();

    std::cout << "\nConcatenantion 2:\n";
    test1 += "abc";
    test1 += "abc";
    test1.display();

    std::cout << "\nMultiply:\n";
    MyString multiplied {test3 * 3};
    multiplied.display();
    multiplied *= 2;
    multiplied.display();

    std::cout << "\nLexical comparision:\n";
    std::cout << (test3 < test4 ? "true" : "false") << std::endl;
    return 0;
}