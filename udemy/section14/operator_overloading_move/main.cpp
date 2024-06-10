#include <cstddef>
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
    MyString(MyString&& src);
    ~MyString();
    void display() const;
    int get_length() const;
    const char* to_str() const;
    MyString& operator=(const MyString& rhs);
    MyString& operator=(MyString&& rhs);
    bool operator==(const MyString& rhs) const;
    MyString operator+(const MyString& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, MyString& str);
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
    if (str == nullptr) {
        std::cout
            << "Calling desctructor for MyString : nullptr"
            << std::endl;
    } else {
        std::cout
            << "Calling desctructor for MyString : "
            << this->str
            << std::endl;
    }
    delete[] str;
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

MyString& MyString::operator=(MyString&& rhs) {
    std::cout
        << "Move assignment from "
        << to_str()
        << " to "
        << rhs.to_str()
        << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

bool MyString::operator==(const MyString &rhs) const {
    return std::strcmp(str, rhs.str) == 0;
}

MyString MyString::operator+(const MyString &rhs) const {
    char* buffer {new char[std::strlen(str) + std::strlen(rhs.str) + 1]};
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);

    MyString res {buffer};
    delete[] buffer;
    return res;
}

std::ostream& operator<<(std::ostream& os, const MyString& src) {
    os << src.str;
    return os;
}

int main() {
    MyString a {"Hello"}; // Overloaded ctor
    a.display();
    a = MyString{"Hola"}; // Overloaded ctor then move assignment
    a.display();
    a = "Bonjour"; // Overloaded ctor then move assignment
    a.display();

    MyString b {"Bonjour."};
    std::cout << "Is a equal a? " << (a == a ? "true" : "false") << std::endl;
    std::cout << "Is a equal b? " << (a == b ? "true" : "false") << std::endl;

    std::cout << "A + B is: " << (a + b).to_str() << std::endl;

    std::cout << "ostream overload: " << a << std::endl;
    return 0;
}