#include <iostream>
#include <cstring>

class MyString {
private:
    // pointer to a char[] that holds a C-style string
    char* str;
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& src);
    ~MyString();
    void display() const;
    int get_length() const;
    const char* to_str() const;
    MyString& operator=(const MyString& rhs);
};

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

MyString::MyString(const MyString& src) : str{nullptr} {
    str = new char[std::strlen(src.str) + 1];
    std::strcpy(str, src.str);
}

MyString::~MyString() {
    delete [] str;
}

void MyString::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}

int MyString::get_length() const {
    return std::strlen(str);
}

const char* MyString::to_str() const {
    return str;
}

MyString& MyString::operator=(const MyString &rhs) {
    std::cout
        << "Copy assignment from "
        << to_str()
        << " to "
        << rhs.to_str()
        << std::endl;
    if (this == &rhs) {
        return *this;
    }

    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

int main() {
    MyString emtpy;
    MyString larry {"Larry"};
    MyString stooge {larry};
    emtpy = larry;

    emtpy.display();
    larry.display();
    stooge.display();

    return 0;
}