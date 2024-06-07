#include "vehicle_purchase.h"
#include <iostream>

bool vehicle_purchase::needs_license(std::string kind) {
    return kind == "car" || kind == "truck";
}

std::string vehicle_purchase::choose_vehicle(
    std::string option1,
    std::string option2) {
    if (option1 < option2) {
        return option1 + " is clearly a better choice.";
    }
    return option2 + " is clearly a better choice.";
}

double vehicle_purchase::calculate_resell_price(
    double original_price,
    double age) {
    if (age < 3) {
        return (original_price / 100) * 80;
    } else if (age >= 3 && age < 10) {
        return (original_price / 100) * 70;
    }
    return (original_price / 100) * 50;
}

int main() {
    std::cout << vehicle_purchase::needs_license("car") << std::endl;
    std::cout << vehicle_purchase::needs_license("bike") << std::endl;

    std::cout
        << vehicle_purchase::choose_vehicle("Wuling Hongguang", "Toyota Corolla")
        << std::endl;
    std::cout
        << vehicle_purchase::choose_vehicle("Volkswagen Beetle", "Volkswagen Golf")
        << std::endl;
    std::cout
        << vehicle_purchase::choose_vehicle("Bugatti Veyron", "Ford Pinto")
        << std::endl;

    std::cout
        << vehicle_purchase::calculate_resell_price(1'000, 1)
        << std::endl;
    std::cout
        << vehicle_purchase::calculate_resell_price(1'000, 5)
        << std::endl;
    std::cout
        << vehicle_purchase::calculate_resell_price(1'000, 15)
        << std::endl;
    return 0;
}