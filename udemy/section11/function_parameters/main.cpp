#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value_1(int num);
void pass_by_value_2(string s);
void pass_by_value_3(vector<string> v);
void print_vector(vector<string> v);

void pass_by_value_1(int num) {
    num = 100;
}

void pass_by_value_2(string s) {
    s = "Changed";
}

void pass_by_value_3(vector<string> v) {
    v.clear();
}

void print_vector(vector<string> v) {
    for (auto s : v)
        cout << s << " ";
    cout << endl;
}

int main() {
    int num {10};
    int another_num {20};

    cout << "num before calling pass_by_value_1: " << num << endl;
    pass_by_value_1(num);
    cout << "num after calling pass_by_value_1: " << num << endl;

    string name {"Michal"};
    cout << "name before calling pass_by_value_2: " << name << endl;
    pass_by_value_2(name);
    cout << "name after calling pass_by_value_2: " << name << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    cout << "Stooges before calling pass_by_value_3: ";
    print_vector(stooges);
    pass_by_value_3(stooges);
    cout << "Stooges after calling pass_by_value_3: ";
    print_vector(stooges);
    return 0;
}