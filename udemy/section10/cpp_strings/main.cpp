#include <iostream>
#include <string>

using namespace std;

int main() {
    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {s1, 0, 3}; // App
    string s5 (10, '-'); // ----------

    cout << s0 << endl; // No garbage
    cout << s0.length() << endl;

    cout << s4 << endl;
    cout << s5 << endl;

    cout << (s1 > s2) << endl;

    string concat {s1 + " and " + s2 + " juice"};
    cout << concat << endl;

    // Iteration
    for (auto ch : s1)
        cout << ch;
    cout << endl;

    // Substring
    cout << concat.substr(0, 5) << endl;

    // Erase
    string test {"This is a test"};
    test.erase(0, 5);
    cout << test << endl; // is a test
    return 0;
}