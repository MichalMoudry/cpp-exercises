#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    char full_name[50] {};

    cout << "Enter your full name: ";
    cin.getline(full_name, 50);

    cout << "Your full name is: " << full_name << " | " << strcmp(full_name, "Michal Moudrý") << endl;
    return 0;
}