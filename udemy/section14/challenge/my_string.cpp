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

MyString::MyString(const MyString& src) : str{nullptr} {
    str = new char[std::strlen(src.str) + 1];
    std::strcpy(str, src.str);
}

MyString::MyString(const MyString&& src) : str{nullptr} {
    str = new char[std::strlen(src.str) + 1];
    std::strcpy(str, src.str);
}

MyString& MyString::operator=(const MyString& src) {
    if (this == &src) {
        return *this;
    }

    delete [] str;
    str = new char[std::strlen(src.str) + 1];
    std::strcpy(str, src.str);
    return *this;
}

MyString& MyString::operator=(MyString&& src) {
    if (this == &src) {
        return *this;
    }

    delete [] str;
    str = src.str;
    src.str = nullptr;
    return *this;
}

MyString MyString::operator-() const {
    auto buffer {new char[get_length() + 1]};
    for (int i {0}; i < get_length(); i++) {
        buffer[i] = std::tolower(str[i]);
    }
    return buffer;
}

bool MyString::operator==(const MyString& rhs) const {
    if (this == &rhs) {
        return true;
    }

    auto rhs_len {rhs.get_length()};
    auto lhs_len {get_length()};
    if (lhs_len != rhs_len) {
        return false;
    }
    for (int i {0}; i < lhs_len; i++) {
        if (str[i] != rhs.str[i]) {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& rhs) const {
    return !(*this == rhs);
}

MyString MyString::operator+(const MyString& rhs) const {
    auto res {new char[get_length() + rhs.get_length() + 1]};
    std::strcpy(res, str);
    std::strcat(res, rhs.str);
    return res;
}

MyString& MyString::operator+=(const MyString &rhs) {
    auto buffer {new char[get_length() + rhs.get_length() + 1]};

    std::strcpy(buffer, str);
    delete [] str;
    std::strcat(buffer, rhs.str);
    str = buffer;
    return *this;
}
