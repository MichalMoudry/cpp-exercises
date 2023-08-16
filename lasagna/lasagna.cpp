#include <iostream>

int ovenTime() {
    return 40;
}

int remainingOvenTime(int actualMinutesInOven) {
    return ovenTime() - actualMinutesInOven;
}

int preparationTime(int numberOfLayers) {
    return numberOfLayers * 2;
}

int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return actualMinutesInOven + preparationTime(numberOfLayers);
}

int main() {
    int test = ovenTime();
    std::cout << test << std::endl;
    std::cout << remainingOvenTime(30) << std::endl;
    std::cout << preparationTime(2) << std::endl;
    std::cout << elapsedTime(3, 20) << std::endl;
}
