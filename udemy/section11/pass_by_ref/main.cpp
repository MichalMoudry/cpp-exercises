#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num) {
    num = 1'000;
}

void pass_by_ref2(string &s) {
    s = "Changed";
}

void pass_by_ref3(vector<string> &v) {
    v.clear();
}

void print_vector(const vector<string> &v) {
    for (auto item : v) {
        cout << item << endl;
    }
}

int main() {
    int num {10};
    int another_num {20};

    pass_by_ref1(num);
    cout << num << endl;

    string test {"temp string"};
    pass_by_ref2(test);
    cout << test << endl;

    vector<string> vec {"test 1", "test 2"};
    print_vector(vec);
    pass_by_ref3(vec);
    print_vector(vec);
    return 0;
}