//
// Created by Michal Moudrý on 31.01.2024.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> test_scores {100, 95, 99, 87};
    cout << test_scores.at(1) << endl;
    test_scores.push_back(90);
    test_scores.push_back(80);
    cout << "Last element: " << test_scores.at(5) << endl;

    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    vector <int> test_scores_2 (3, 100);
    cout << test_scores_2.at(0) << endl;
    cout << test_scores_2.at(1) << endl;
    cout << test_scores_2.at(2) << endl;
    cout << "Test scores v2 has size of " << test_scores_2.size() << endl;
    int test_score {};
    cin >> test_score;
    test_scores_2.push_back(test_score);
    cout << "Test scores v2 has size of " << test_scores_2.size() << endl;
    cout << test_scores_2.at(10) << endl;
    return 0;
}
