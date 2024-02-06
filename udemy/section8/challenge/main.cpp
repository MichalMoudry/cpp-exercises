//
// Created by Michal Moudrý on 05.02.2024.
//
#include <iostream>

using namespace std;

int main() {
    int cents_number {0};
    cout << "Enter an amount in cents: ";
    cin >> cents_number;

    int dollars {cents_number/100};
    cout << "dollars: " << dollars << endl;
    cents_number %= 100;

    int quarters {cents_number/25};
    cout << "quarters: " << quarters << endl;
    cents_number %= 25;

    int dimes {cents_number/10};
    cout << "dimes: " << cents_number/10 << endl;
    cents_number %= 10;

    int nickles {cents_number/5};
    cout << "nickles: " << nickles << endl;
    cents_number %= 5;

    int pennies {cents_number/1};
    cout << "pennies: " << pennies << endl;
    return 0;
}
