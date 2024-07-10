#include <iostream>

int main(int argc, char const *argv[]) {
    int miles {};
    int gallons {};
    double miles_per_galon {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    //miles_per_galon = miles / gallons;
    try {
        if (gallons == 0) {
            throw 0;
        }
        miles_per_galon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_galon << std::endl;
    }
    catch (int& ex) {
        std::cerr << "Sorry, you can't devide by zero" << std::endl;
    }
    return 0;
}
