#include <iostream>

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw 0;
    }
    if (miles < 0 || gallons < 0) {
        throw std::string {"miles or gallons are negative"};
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
    catch (int& ex) {
        std::cerr << "Sorry, you can't devide by zero" << std::endl;
    }
    catch (std::string& ex) {
        std::cerr << "[Error]: " << ex << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception" << std::endl;
    }

    return 0;
}
