#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class MyString {
private:
    char* str;
public:
    MyString();
    MyString(const char* src);
    MyString(const MyString& src);
    MyString(const MyString&& src);
    ~MyString() {
        delete [] str;
    }

    MyString& operator=(const MyString& src);
    MyString& operator=(MyString&& src);
    MyString operator-() const;
    bool operator==(const MyString& rhs) const;
    bool operator!=(const MyString& rhs) const;
    bool operator<(const MyString& rhs) const;
    MyString operator+(const MyString& rhs) const;
    MyString& operator+=(const MyString& rhs);
    MyString operator*(int num) const;
    MyString& operator*=(int num);

    void display() const {
        auto str_len {get_length()};
        if (str_len == 0) {
            std::cout << "emtpy";
        } else {
            std::cout << str;
        }
        std::cout << ": " << str_len << std::endl;
    }
    int get_length() const {
        return std::strlen(str);
    }
    const char* to_str() const {
        return str;
    }
};

#endif