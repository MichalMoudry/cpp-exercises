#include <iostream>
#include "cmath"
using namespace std;

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * 8;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount - (before_discount/100) * discount;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    return (int)(
        ceil(
            apply_discount(22 * daily_rate(hourly_rate), discount)
        )
    );
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    int month_rate{monthly_rate(hourly_rate, discount)};
    return floor(
        ((double)budget/month_rate)*22
    );
}

int main() {
    cout << daily_rate(60) << endl;
    cout << apply_discount(150, 10) << endl;
    cout << monthly_rate(77, 10.5) << endl;
    cout << days_in_budget(20'000, 80, 11.0) << endl;
    return 0;
}
