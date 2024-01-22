#include "rain_drops.h"
#include <iostream>

namespace raindrops {
    std::string convert(int value)
    {
        if (value % 3 != 0 && value % 5 != 0 && value % 7 != 0)
        {
            return std::to_string(value);
        }
        std::string result = "";
        if (value % 3 == 0)
        {
            result += "Pling";
        }
        if (value % 5 == 0)
        {
            result += "Plang";
        }
        if (value % 7 == 0)
        {
            result += "Plong";
        }
        return result;
    }
}

int main() {
    std::cout << raindrops::convert(1) << std::endl;
    std::cout << raindrops::convert(3) << std::endl;
    std::cout << raindrops::convert(105) << std::endl;
    std::cout << raindrops::convert(5) << std::endl;
}
