#include <iostream>

using namespace std;

double calc_volume_cylinder(double radius, double height);
double calc_area_circle(double radius);
void area_circle();

const double pi {3.14159};

int main() {
    area_circle();
    return 0;
}

double calc_area_circle(double radius) {
    return pi * radius * radius;
}

double calc_volume_cylinder(double radius, double height) {
    return calc_area_circle(radius) * height;
}

void area_circle() {
    double radius {};
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout
        << "The area of a circle with radius "
        << radius
        << " is "
        << calc_area_circle(radius)
        << endl;
}