#include <iostream>

using namespace std;

int main() {
    const double price_per_room {32.5};
    const double tax_rate {0.06};
    const int estimate_expiry {30};

    cout << "Hello, welcome to Cleaning Service!\n" << endl;
    int number_of_rooms {0};
    cout << "Enter number of rooms: ";
    cin >> number_of_rooms;
    cout << "You have entered " << number_of_rooms << " rooms" << endl;
    cout << "Price per room: " << price_per_room << "$" << endl;

    double cost {number_of_rooms * price_per_room};
    cout << "Room cost: " << cost << "$" << endl;

    double tax {number_of_rooms * price_per_room * tax_rate};
    cout << "Tax: " << tax << "$" << endl;

    cout << "============================" << endl;
    double total_estimate {cost + tax};
    cout << "Total estimate: " << total_estimate << "$" << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days";

    return 0;
}
