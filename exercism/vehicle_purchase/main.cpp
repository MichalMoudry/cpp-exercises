#include "vehicle_purchase.h"
#include <iostream>

bool vehicle_purchase::needs_license(std::string kind) {
    return kind == "car" || kind == "truck";
}

std::string vehicle_purchase::choose_vehicle(
    std::string option1,
    std::string option2) {
    for (int i = 0; i < option1.length(); i++) {
        if (option1[0] < option2[0]) {
            return option1 + " is clearly a better choice";
        } else {
            return option2 + " is clearly a better choice";
        }
    }
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
    return 0;
}