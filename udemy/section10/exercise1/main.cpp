#include <iostream>
#include <string>

using namespace std;

// Exercise 1
void cpp_strings() {
    string unformatted_full_name {"StephenHawking"};

    string first_name {unformatted_full_name, 0, 7};
    string last_name (unformatted_full_name, 7, unformatted_full_name.length());

    string formatted_full_name {first_name + " " + last_name};
    cout << formatted_full_name << endl;
}

// Exercise 2
void cpp_strings_2() {
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};

    journal_entry_1.erase(0, 6);
    if (journal_entry_2 < journal_entry_1) {
        swap(journal_entry_1, journal_entry_2);
    }

    cout << journal_entry_1 << endl << journal_entry_2 << endl;
}

int main() {
    cpp_strings_2();
    return 0;
}