#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double num {};

    cout << "Enter a number (double): ";
    cin >> num;

    cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;

    return 0;
}