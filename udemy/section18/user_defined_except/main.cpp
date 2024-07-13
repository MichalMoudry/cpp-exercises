#include <iostream>

class DivideByZeroException final {};

class NegativeValueException final {};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw DivideByZeroException();
    }
    if (miles < 0 || gallons < 0) {
        throw NegativeValueException();
    }

    return static_cast<double>(miles) / gallons;
}

int main(int argc, char const *argv[]) {
    int miles {};
    int gallons {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
        double miles_per_galon {calculate_mpg(miles, gallons)};
        std::cout << "Result: " << miles_per_galon << std::endl;
    }
    catch (const DivideByZeroException& ex) {
        std::cerr << "Sorry, you can't devide by zero" << std::endl;
    }
    catch (const NegativeValueException& ex) {
        std::cerr << "Miles or gallons are negative" << std::endl;
    }

    std::cout << "Bye..." << std::endl;
    return 0;
}
