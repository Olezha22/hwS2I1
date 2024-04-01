#include "container.h"
#include <fstream>


CarContainer::CarContainer()
	: size(0), carTravels(nullptr)
{}
CarContainer::CarContainer(int n, CarTravel** CT)
	: size(n), carTravels(CT)
{}
CarContainer::~CarContainer()
{
	for (int i = 0; i < size; ++i) {
		delete carTravels[i];
	}
	delete[] carTravels;
}

void CarContainer::addCarTravel() {
    std::ifstream file("travels.txt");
    file >> size;

    carTravels = new CarTravel * [size];

    std::string type, destination, typeCar, typePlane;
    double distance;
    int familyMembers;
    double consumption, price;
    int realSize = 0;

    for (int i = 0; i < size; ++i) {
        file >> type >> destination;
        if (type == "Car") {
            file >> typeCar >> consumption >> distance;
            carTravels[realSize] = new CarTravel(new Car(typeCar, consumption), destination, distance);
            realSize++;
        }
        else if (type == "Airplane") {
            file >> typePlane >> price >> familyMembers;
        }
    }

    size = realSize;

    file.close();
}

void CarContainer::printCarTravels() const {
    std::cout << "Car Travels:" << std::endl;
    for (int i = 0; i < size; ++i) {
        carTravels[i]->print();
    }
}

const Transport* CarContainer::getCarFromHighest() const
{
    double maxCost = carTravels[0]->calculatePrice();
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (carTravels[i]->calculatePrice() > maxCost)
        {
            maxCost = carTravels[i]->calculatePrice();
            maxIndex = i;
        }
    }

    const Transport* car = carTravels[maxIndex]->getTransport();

    return car;
}



AirContainer::AirContainer()
    : airTravels(nullptr), size(0)
{}

AirContainer::AirContainer(int n, AirTravel** AT)
    : size(n), airTravels(AT)
{
}

AirContainer::~AirContainer() {
    for (int i = 0; i < size; ++i) {
        delete airTravels[i];
    }
    delete[] airTravels;
}

void AirContainer::addAirTravel() {
    std::ifstream file("travels.txt");
    file >> size;

    airTravels = new AirTravel * [size];

    std::string type, destination, typeCar, typePlane;
    double distance;
    int familyMembers;
    double consumption, price;
    int realSize = 0;

    for (int i = 0; i < size; ++i) {
        file >> type >> destination;
        if (type == "Car") {
            file >> typeCar >> consumption >> distance;
        }
        else if (type == "Airplane") {
            file >> typePlane >> price >> familyMembers;
            airTravels[realSize] = new AirTravel(new Airplane(typePlane, price), destination, familyMembers);
            realSize++;
        }
    }

    size = realSize;

    file.close();
}

void AirContainer::printAirTravels() const {
    std::cout << "Air Travels:" << std::endl;
    for (int i = 0; i < size; ++i) {
        airTravels[i]->print();
    }
}


int AirContainer::findCheapMembers() const
{
    double minCost = airTravels[0]->calculatePrice();
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (airTravels[i]->calculatePrice() < minCost)
        {
            minCost = airTravels[i]->calculatePrice();
            minIndex = i;
        }
    }

    return airTravels[minIndex]->getFamilyMembers();
}
