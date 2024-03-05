#include <iostream>

using namespace std;

int main() {
    int num {};

    cout << "Enter an int: ";
    cin >> num;

    string res {num % 2 == 0 ? "even" : "odd"};
    cout << res;

    cout << endl;
    return 0;
}