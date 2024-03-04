#include <iostream>

using namespace std;

int main() {
    enum Color {
        red, green, blue
    };

    Color color {red};
    switch (color) {
        case red:
            cout << "red" << endl;
            break;
        case green:
            cout << "green" << endl;
            break;
        case blue:
            cout << "blue" << endl;
            break;
        default:
            cout << "unknown" << endl;
    }

    char letter_grade {};
    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;

    switch (letter_grade) {
        case 'a':
        case 'A':
            cout << "You need a 90 or above" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80-89 for a B" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You need 70-79 for an average grade" << endl;
            break;
        case 'd':
        case 'D':
            cout << "Hmm" << endl;
            break;
        case 'f':
        case 'F':
        {
            char confirm {};
            cout << "Are you sure? (Y/N)" << endl;
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
                cout << "Ok" << endl;
            else if (confirm == 'n' || confirm == 'N')
                cout << "Good" << endl;
            else
                cout << "Illegal choice..." << endl;
            break;
        }
        default: cout << "That is not a valid grade" << endl;
    }
    return 0;
}