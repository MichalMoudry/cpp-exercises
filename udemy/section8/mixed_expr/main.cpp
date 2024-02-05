//
// Created by Michal Moudrý on 05.02.2024.
//
#include <iostream>

using namespace std;

int main() {
    int total {};
    int num1 {}, num2 {}, num3{};

    cout << "Enter 3 integers separated by spaces: ";
    cin >> num1 >> num2 >> num3;
    total = num1 + num2 + num3;

    double average {0.0};
    average = static_cast<double>(total) / 3;

    cout << "The 3 numbers were: " << num1 << "," << num2 << "," << num3 << endl;
    cout << "Sum: " << total << endl;
    cout << "Average: " << average << endl;
    return 0;
}
