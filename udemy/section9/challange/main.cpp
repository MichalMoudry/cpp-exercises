#include <iostream>
#include <vector>

using namespace std;

// Method for printing current state of the collection.
void print_numbers(const vector<int>& vec) {
    cout << "[";
    for (const auto& num : vec) {
        cout << num << " ";
    }
    cout << "]";
}

void handle_number_adding(vector<int>& vec) {
    int number{};
    cout << "Which number do you want to add? ";
    cin >> number;
    vec.push_back(number);
    cout << endl;
    cout << "Added " << number;
}

void handle_input(char input, vector<int>& vec) {
    switch (input) {
        case 'p':
        case 'P':
            print_numbers(vec);
            break;
        case 'a':
        case 'A':
            handle_number_adding(vec);
            break;
        default:
            break;
    }
}

int main() {
    vector<int> numbers {};

    char input {};
    do {
        cout << "Working collection: ";
        print_numbers(numbers);
        cout << endl << endl;

        cout << "Enter on of the following:" << endl;
        cout << "P - print numbers" << endl;
        cout << "A - add a number" << endl;
        cout << "M - display mean of numbers" << endl;
        cout << "S - display the smallest number" << endl;
        cout << "L - display the largest number" << endl;
        cout << "Q - quit" << endl;

        cout << endl << "Your choice: ";
        cin >> input;

        handle_input(input, numbers);
        cout << endl << endl;
    } while(input != 'q' && input != 'Q');

    return 0;
}