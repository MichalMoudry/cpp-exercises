#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10 + sum_of_digits(n / 10));
}

int main() {
    cout << sum_of_digits(1234) << endl;
    return 0;
}