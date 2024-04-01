#include <iostream>
#include "travel.h"
#include "transport.h"
#include "container.h"

int main() {


    int n;
    Travel** travels;

    readTravelsFromFile("travels.txt", travels, n);

    double totalCost, maxCar, maxAir;

    calculateCosts(travels, n, totalCost, maxCar, maxAir);

    printResults(travels, n, totalCost, maxCar, maxAir);

    for (int i = 0; i < n; ++i) {
        delete travels[i];
    }
    delete[] travels;



    CarContainer car;
    AirContainer air;
    car.addCarTravel();
    air.addAirTravel();
    air.printAirTravels();
    car.printCarTravels();
    std::cout << "Lowest airTravel. members = " << air.findCheapMembers() << "\n";
    std::cout << "Highest carTravel. car = " << car.getCarFromHighest()->getCarBrand() << "\n";

    return 0;
}
