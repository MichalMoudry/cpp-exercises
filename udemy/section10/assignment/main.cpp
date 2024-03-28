#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "Enter your letters for the pyramid: ";

    string input;
    getline(cin, input);
    size_t input_length {input.length()};
    if (input_length == 0) {
        cout << "You have entered an empty string" << endl;
        return 0;
    }

    string row_padding;
    for (int i {}; i < input_length; i++) {
        row_padding = string (input_length - 1 - i, ' ');
        cout << row_padding << input.substr(0, i + 1);
        if (i != 0) {
            for (int y {i - 1}; y >= 0; y--) {
                cout << input.at(y);
            }
        }
        cout << endl;
    }
    return 0;
}