#include <iostream>
#include <iomanip>
#include <sstream>

int main() {
    int num {};
    double total {};
    std::string name {};

    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info};
    iss >> name >> num >> total;
    std::cout
        << std::setw(10) << std::left << name
        << std::setw(5) <<  num
        << std::setw(10) << total << std::endl;

    std::cout << "---------------------" << std::endl;

    std::ostringstream oss {};
    oss << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total << std::endl;
    std::cout << "ostringstream output: " << oss.str() << std::endl;

    std::cout << "---------------------" << std::endl;

    int value {};
    std::string entry {};
    bool done {};
    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;
        std::istringstream validator {entry};
        if (validator >> value) {
            std::cout << entry << " is an integer!" << std::endl;
            done = true;
        } else {
            std::cout << entry << " is not an integer..." << std::endl;
        }

        // discard input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (done != true);

    return 0;
}