#include <iostream>

using namespace std;

void swap_pointers(int* ptr1, int* ptr2) {
    int temp {*ptr1};
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a {5};
    int b {10};

    int* ptrA = &a;
    int* ptrB = &b;

    cout << "Pointer A pointing to: " << *ptrA << endl;
    cout << "Pointer B pointing to: " << *ptrB << endl;
    swap_pointers(ptrA, ptrB);
    cout << "Pointer A pointing to: " << *ptrA << endl;
    cout << "Pointer B pointing to: " << *ptrB << endl;
    return 0;
}