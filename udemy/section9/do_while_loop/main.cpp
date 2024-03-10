#include <iostream>
#include <vector>

using namespace std;

/*int main() {
    int number {};
    do {
        cout << "Enter an integer between 1 and 5: ";
        cin >> number;
    } while (number <= 1 || number >= 5);
    cout << "thanks" << endl;
    return 0;
}*/

void find_first_vowel(const vector<char>& vec) {
    size_t vec_size {vec.size()};
    if (vec_size == 0) {
        cout << "No vowel was found";
        return;
    }

    int i {};
    char current;
    bool wasFound {};
    do {
        current = vec[i];
        if (current == 'a'
            || current == 'e'
            || current == 'i'
            || current == 'o'
            || current == 'u') {
            cout << "Found vowel: " << current;
            wasFound = true;
            break;
        }
        i++;
    } while (i <= vec_size);

    if (!wasFound) {
        cout << "No vowel was found";
    }
}

int main() {
    vector<char> vec1 {'f', 'r', 'a', 'n', 'k'};
    find_first_vowel(vec1);

    cout << endl;

    vector<char> vec2 {'F', 'R', 'A', 'N', 'K'};
    find_first_vowel(vec2);

    cout << endl;
    vector<char> vec3 {};
    find_first_vowel(vec3);
    return 0;
}