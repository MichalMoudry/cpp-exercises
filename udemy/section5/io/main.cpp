#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Hello world!" << endl;
    cout << "Hello";
    cout << "World!" << endl;

    cout << "Hello" << " world!\n";
    cout << "Hello\nOut\nThere\n";

    int num1;
    int num2;
    double num3;

    /*cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter a second integer: ";
    cin >> num2;
    cout << "You entered: " << num1 << " and " << num2 << endl;*/
    /*cout << "Enter two integers sparated with a space: ";
    cin >> num1 >> num2;
    cout << "You entered: " << num1 << " and " << num2 << endl;*/

    /*cout << "Enter a double: ";
    cin >> num3;
    cout << "You entered: " << num3 << endl;*/

    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter a double: ";
    cin >> num3;
    cout << "The integer is: " << num1 << endl;
    cout << "The double is: " << num3 << endl;
    return 0;
}
