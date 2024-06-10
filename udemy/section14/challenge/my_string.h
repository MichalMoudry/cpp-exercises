#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class MyString {
private:
    char* str;
public:
    MyString();
    MyString(const char* src);
    MyString(const MyString& src);
    MyString(const MyString&& src);
    ~MyString();

    MyString& operator=(const MyString& src);
    MyString& operator=(MyString&& rhs);

    void display() const;
    int get_length() const;
    const char* to_str() const;
};

#endif