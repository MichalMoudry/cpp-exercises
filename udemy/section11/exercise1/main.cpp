#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double bill_total {102.78};
    int number_of_guests {5};

    double individual_bill {bill_total / number_of_guests};
    double individual_bill_1 {floor(individual_bill)};
    double individual_bill_2 {round(individual_bill)};
    double individual_bill_3 {ceil(individual_bill * 100) / 100};

    cout
        << "The individual bill at location 1 will be $"
        << individual_bill_1
        << "\n" << "The individual bill at location 2 will be $"
        << individual_bill_2
        << "\n"
        << "The individual bill at location 3 will be $"
        << individual_bill_3;
    return 0;
}