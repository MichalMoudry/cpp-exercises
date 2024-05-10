#include <cstddef>
#include <cstdio>
#include <iostream>

using namespace std;

/*
write a function named apply_all that expects two arrays of integers and their sizes
and dynamically allocates a new array of integers whose size is the product of
the 2 array sizes

the function should loop through the second array and multiple each element across
each element of array 1 and store the product in the newly created array

the function should return a pointer to the newly allocated array

you can also write a function that expects a pointer to an array of integers and its
size and display the elements in the array
*/

int* apply_all(int* arr1, size_t arr1_size, int* arr2, size_t arr2_size) {
    auto result {new int[arr1_size * arr2_size]};
    int current_index {0};
    for (int i = 0; i < arr2_size; i++) {
        for (int y = 0; y < arr1_size; y++) {
            result[current_index] = arr2[i] * arr1[y];
            current_index += 1;
        }
    }
    return result;
}

void print_array(const int* const arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int array1[] {1, 2, 3, 4, 5};
    auto arr1_size {sizeof(array1) / sizeof(array1[0])};
    int array2[] {10, 20, 30};
    auto arr2_size {sizeof(array2) / sizeof(array2[0])};

    cout << "Array 1:" << endl;
    print_array(array1, arr1_size);
    cout << "Array 2:" << endl;
    print_array(array2, arr2_size);

    auto results {apply_all(array1, arr1_size, array2, arr2_size)};
    if (results != nullptr) {
        printf("Result array:\n");
        print_array(results, arr1_size * arr2_size);
        delete [] results;
    } else {
        printf("Result is empty\n");
    }
    return 0;
}