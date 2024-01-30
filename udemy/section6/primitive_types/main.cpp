#include <iostream>

using namespace std;

int main() {
    char middle_initial {'M'};
    cout << middle_initial << endl;

    unsigned short exam_score {55};
    cout << "My exam score was: " << exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented << endl;

    long people {7'600'000'000};
    cout << "There are about " << people << " people on earth" << endl;

    long long distance_to_alpha_centauri {9'461'000'000'000};
    cout << "The distance to alpha centauri is " << distance_to_alpha_centauri << " km" << endl;

    // --- Floating points ---
    float car_payment {401.32};
    double pi {3.14159};
    long double large_amount {2.7e120};
    cout << large_amount << " is a very big number" << endl;

    // --- Boolean type ---
    bool game_over {false};
    cout << "The value of game over is: " << game_over << endl;

    // Overflow example
    short value1 {30'000};
    short value2 {1'000};
    short product {value1 * value2}; // => Error narrowing conversion
    cout << "The sum of " << value1 << " and " << value2 << " is " << product << endl;
    return 0;
}