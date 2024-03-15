#include <iostream>
#include <vector>

using namespace std;

// Function for printing current state of the collection.
void print_numbers(const vector<int>& numbers) {
    cout << "[";
    if (numbers.size() > 0) {
        cout << " ";
    }

    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << "]";
}

void handle_number_adding(vector<int>& numbers) {
    int number {};
    cout << "Which number do you want to add? ";
    cin >> number;
    numbers.push_back(number);
    cout << endl;
    cout << "Added " << number;
}

// Function for printing a mean of current numbers in a vector.
void print_mean(vector<int>& numbers) {
    size_t vec_size {numbers.size()};
    if (vec_size == 0) {
        cout << "Unable to calculate the mean - no data";
    }
    else {
        int sum {};
        for (const auto& num : numbers) {
            sum += num;
        }
        cout << "Mean of current numbers is: " << (sum/(float)vec_size);
    }
}

// Function for printing the smallest number in a vector.
void print_smallest_number(vector<int>& numbers) {
    size_t vec_size {numbers.size()};
    if (vec_size == 0) {
        cout << "Unable to determine the smallest number - list is empty";
    }
    else {
        int smallest {numbers[0]};
        int next_index;
        for (int i {}; i < vec_size; i++) {
            next_index = i + 1;
            if (next_index == vec_size) break;
            if (numbers.at(next_index) < smallest) {
                smallest = numbers.at(next_index);
            }
        }
        cout << "Smallest number is: " << smallest;
    }
}

// Function for printing the largest number in a vector.
void print_largest_number(vector<int> &numbers) {
    size_t vec_size {numbers.size()};
    if (vec_size == 0) {
        cout << "Unable to determine the largest number - list is empty";
    }
    else {
        int largest {numbers[0]};
        int next_index;
        for (int i {}; i < vec_size; i++) {
            next_index = i + 1;
            if (next_index == vec_size) break;
            if (numbers.at(next_index) > largest) {
                largest = numbers.at(next_index);
            }
        }
        cout << "Largest number is: " << largest;
    }
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
        case 'm':
        case 'M':
            print_mean(vec);
            break;
        case 's':
        case 'S':
            print_smallest_number(vec);
            break;
        case 'l':
        case 'L':
            print_largest_number(vec);
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