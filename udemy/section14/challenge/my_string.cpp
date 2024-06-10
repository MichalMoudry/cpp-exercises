#include "my_string.h"

MyString::MyString() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char* s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}