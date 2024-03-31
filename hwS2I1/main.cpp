#include <iostream>
#include <fstream>
#include "travel.h"
#include "transport.h"

int main() {
    int n;
    std::ifstream file("travels.txt");
    file >> n;

    Travel** travels = new Travel * [n]; 

    std::string type, destination;
    double distance;
    int familyMembers;
    double consuption;

    for (int i = 0; i < n; ++i)
    {
        file >> type >> destination;
        if (type == "Car") {
            file >> consuption >> distance;
            travels[i] = new CarTravel(new Car(), destination, distance); 
        }
        else if (type == "Airplane") {
            file >> familyMembers;
            travels[i] = new AirTravel(new Airplane(), destination, familyMembers); 
        }
    }

    file.close();


    travels[0]->print();
    

    // Clean up allocated memory
    for (int i = 0; i < n; ++i) {
        delete travels[i];
    }
    delete[] travels; // Видалення масиву вказівників

    return 0;
}
