#include <iostream>

using namespace std;

void reverse_array_2(int* arr, int size) {
    int* start {arr};
    int* end {arr + size - 1};
    int temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void reverse_array(int* arr, int size) {
    int reverse_index {size - 1};
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[reverse_index];
        arr[reverse_index] = temp;

        reverse_index -= 1;
    }
}

int main() {
    int arr[] {1, 2, 3, 4, 5, 6, 7};
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