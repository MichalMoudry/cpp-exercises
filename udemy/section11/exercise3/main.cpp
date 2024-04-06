#include <iostream>

using namespace std;

void print_grocery_list(int apples = 3, int oranges = 7, int mangos = 13);

void modify_grocery_list() {
    print_grocery_list();
    print_grocery_list(5);
    print_grocery_list(7, 11);
}

void print_grocery_list(int apples, int oranges, int mangos) {
    cout
        << apples
        << " apples"
        << endl
        << oranges
        << " oranges"
        << endl
        << mangos
        << " mangos"
        << endl;
}

int main() {
    modify_grocery_list();
    return 0;
}