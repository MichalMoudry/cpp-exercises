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

    std::ostringstream oss {};
    std::cout << "ostringstream output: " << oss.str() << std::endl;

    return 0;
}