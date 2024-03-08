#include <iostream>

using namespace std;

int main() {
    int num {};
    cout << "Enter a positive int to count up to: ";
    cin >> num;

    int i {1};
    while (num >= i) {
        cout << i << endl;
        i++;
    }

    /*int number {};
    cout << "Enter a number less than 100: ";
    cin >> number;

    while (num >= 100) {
        cout << "Enter a number less than 100: ";
        cin >> number;
    }*/

    bool done {false};
    int number {0};

    while (!done) {
        cout << "Enter an integer between 1 and 5: ";
        cin >> number;
        if (number <= 1 || number >= 5) {
            cout << "out of range" << endl;
        }
        else {
            cout << "thanks" << endl;
            done = true;
        }
    }
    return 0;
}
