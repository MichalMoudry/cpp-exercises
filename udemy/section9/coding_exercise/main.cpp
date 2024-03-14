#include <iostream>
#include <vector>

using namespace std;

int calculate_pairs(vector<int> vec) {
    size_t vec_size{vec.size()};
    if (vec_size <= 1) {
        return 0;
    }

    int result{};
    for (int i{}; i < vec_size; i++) {
        for (int y{i+1}; y < vec_size; y++) {
            result += vec.at(i) * vec.at(y);
        }
    }
    return result;
}

int main() {
    vector<int> vec1 {1, 2, 3};
    cout << "Result 1: " << calculate_pairs(vec1) << endl;

    vector<int> vec2 {2, 4, 6, 8};
    cout << "Result 2: " << calculate_pairs(vec2) << endl;
    return 0;
}