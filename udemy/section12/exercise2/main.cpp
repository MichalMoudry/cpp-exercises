#include <iostream>

using namespace std;

void multiply_with_pointer(int* ptr, int multiplier) {
    *ptr *= multiplier;
}

int main() {
    int test1 {100};
    int test2 {200};
    int test3 {55};

    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;

    multiply_with_pointer(&test1, 3);
    multiply_with_pointer(&test2, 2);
    multiply_with_pointer(&test3, 4);

    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    return 0;
}