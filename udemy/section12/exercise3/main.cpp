#include <iostream>

using namespace std;

int findMaxElement(int* arr, int size) {
    int res {arr[0]};
    for (int i {0}; i < size; ++i) {
        if (i == size - 1) {
            break;
        }

        if (res < arr[i+1]) {
            res = arr[i+1];
        }
    }
    return res;
}

int main() {
    int arr[] {12, 45, 67, 23, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_element = findMaxElement(arr, size);

    cout << max_element << endl;
    return 0;
}