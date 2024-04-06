#include <iostream>
#include <string>

using namespace std;

void print(int val);
void print(string val);
void print(char val);

void print(int val) {
    cout << "Int is: " << val << endl;
}

void print(string val) {
    cout << "String is: " << val << endl;
}

void print(char val) {
    cout << "Char is: " << val << endl;
}

int main() {
    string s {"Test C++ string"};
    print("Test");
    print(s);

    print(5);
    print('s');
    return 0;
}