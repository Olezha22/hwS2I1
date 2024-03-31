#include "travel.h"

Travel::Travel() 
    : transport(nullptr), destination("") 
{}

Travel::Travel(Transport* transport, const std::string& destination) 
    : transport(transport), destination(destination) 
{}

Travel::Travel(const Travel& T) 
    : destination(T.destination) 
{
    if (T.transport)
        transport = T.transport->clone();
    else
        transport = nullptr;
}

Travel::~Travel() 
{
    delete transport;
}

void Travel::print() const {
    std::cout << "Destination: " << destination << std::endl;
}

void Travel::readFrom(std::istream& is) {
    is >> destination;
}

const Transport* Travel::getTransport() const {
    return transport;
}

std::istream& operator>>(std::istream& is, Travel& T) {
    T.readFrom(is);
    return is;
}



CarTravel::CarTravel() 
    : distance(0.0) 
{}

CarTravel::CarTravel(Transport* transport, const std::string& destination, double distance)
    : Travel(transport, destination), distance(distance) 
{}

CarTravel::CarTravel(const CarTravel& C) 
    : Travel(C), distance(C.distance) 
{}

CarTravel::~CarTravel() 
{}

double CarTravel::calculatePrice() const {
    return transport->calculatePrice() * distance;
}

void CarTravel::print() const {
    std::cout << "Destination: " << destination << ", Car Brand: " << transport->getCarBrand() << ", Total Cost: " << calculatePrice() << std::endl;
}

void CarTravel::readFrom(std::istream& is) {
    Travel::readFrom(is);
    is >> distance;
}

double CarTravel::getDistance() const {
    return distance;
}


AirTravel::AirTravel() 
    : familyMembers(0) 
{}

AirTravel::AirTravel(Transport* transport, const std::string& destination, int familyMembers)
    : Travel(transport, destination), familyMembers(familyMembers) 
{}

AirTravel::AirTravel(const AirTravel& A) 
    : Travel(A), familyMembers(A.familyMembers) 
{}

AirTravel::~AirTravel() {}

double AirTravel::calculatePrice() const {
    const double ticketPrice = transport->calculatePrice();
    return ticketPrice * familyMembers;
}

void AirTravel::print() const {
    std::cout << "Destination: " << destination << ", Total Cost for " << familyMembers << " family members: " << calculatePrice() << std::endl;
}

void AirTravel::readFrom(std::istream& is) {
    Travel::readFrom(is);
    is >> familyMembers;
}

int AirTravel::getFamilyMembers() const {
    return familyMembers;
}

