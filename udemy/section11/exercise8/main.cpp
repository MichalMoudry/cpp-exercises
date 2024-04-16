#include <iostream>
#include <iomanip>

using namespace std;

double a_penny_doubled_everyday(int, double amount = 0.01);

void amount_accumulated() {
    double total_amount {a_penny_doubled_everyday(18)};

    cout
        <<  "If I start with a penny and doubled it every day for 25 days, I will have $"
        << setprecision(10)
        << total_amount
        << endl;
}

double a_penny_doubled_everyday(int n, double amount) {
    if (n == 1) {
        return amount;
    }
    return a_penny_doubled_everyday(n-1, amount * 2);
}

int main() {
    amount_accumulated();
    return 0;
}