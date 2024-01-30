//
// Created by Michal Moudrý on 30.01.2024.
//
#include <iostream>

using namespace std;

int main() {
    char vowels[] {'a', 'e', 'i', 'o', 'u'};
    cout << "The first vowel is: " << vowels[0] << endl;
    cout << "Last vowel is: " << vowels[4] << endl;

    double hi_temps[] {90.1, 89.8, 77.5, 81.6};
    cout << "The first high temperature is: " << hi_temps[0] << endl;
    hi_temps[0] = 100.7;
    cout << "The first high temperature is now: " << hi_temps[0] << endl;

    int test_scores[3] {100, 90, 80};
    cout << "First test score at index 0: " << test_scores[0] << endl;
    cout << "Second test score at index 1: " << test_scores[1] << endl;
    cout << "Third test score at index 3: " << test_scores[2] << endl;
    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cout << "First test score at index 0: " << test_scores[0] << endl;
    cout << "Second test score at index 1: " << test_scores[1] << endl;
    cout << "Third test score at index 3: " << test_scores[2] << endl;

    cout << "Test scores: " << test_scores << endl;
    return 0;
}
