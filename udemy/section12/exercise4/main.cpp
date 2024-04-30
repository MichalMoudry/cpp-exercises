#include <iostream>

using namespace std;

void reverse_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Index: " << (size - 1 - i) << endl;
    }
}

int main() {
    int arr[] {1, 2, 3, 4, 5};
    int size {sizeof(arr) / sizeof(arr[0])};

    for (auto item : arr) {
        cout << item << endl;
    }

    reverse_array(arr, size);

    cout << "---------------------" << endl;
    for (auto item : arr) {
        cout << item << endl;
    }
    return 0;
}