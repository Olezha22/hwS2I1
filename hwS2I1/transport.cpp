#include "transport.h"

Transport::Transport() 
    : transport_type("") 
{}

Transport::Transport(std::string type) 
    : transport_type(type) 
{}

Transport::Transport(const Transport& T) 
    : transport_type(T.transport_type) 
{}

Transport::~Transport() 
{}


std::string Car::getCarBrand() const {
    return transport_type;
}

std::string Airplane::getCarBrand() const
{
    return airlineName;
}

bool Car::isCar() const
{
    return true;
}

bool Airplane::isCar() const
{
    return false;
}

void Transport::print() const {
    std::cout << "Transport Type: " << transport_type << std::endl;
}

void Transport::readFrom(std::istream& is) {
    std::getline(is, transport_type, ',');
}

std::istream& operator>>(std::istream& is, Transport& transport) {
    transport.readFrom(is);
    return is;
}


Car::Car() 
    : Transport("Car"), fuel_consumption(0.0) 
{}

Car::Car(const std::string& type, double fuel_consumption)
    : Transport(type), fuel_consumption(fuel_consumption) 
{}

Car::Car(const Car& C)
    : Transport(C.transport_type), fuel_consumption(C.fuel_consumption) 
{}

Car::~Car() 
{}

Transport* Car::clone() const {
    return new Car(*this);
}

void Car::print() const {
    std::cout << "Car Type: " << transport_type << ", Fuel Consumption: " << fuel_consumption << " L/100km" << std::endl;
}

double Car::calculatePrice() const {
    const double fuelPricePerLiter = 56; 
    return 0.1 * fuel_consumption * fuelPricePerLiter;
}

void Car::readFrom(std::istream& is) {
    Transport::readFrom(is);
    is >> fuel_consumption;
}



Airplane::Airplane() 
    : Transport("Airplane"), airlineName("Undefined"), ticketPrice(0.0) 
{}

Airplane::Airplane(const std::string& airlineName, double ticketPrice)
    : Transport("Airplane"), airlineName(airlineName), ticketPrice(ticketPrice) 
{}

Airplane::Airplane(const Airplane& A)
    : Transport(A.transport_type), airlineName(A.airlineName), ticketPrice(A.ticketPrice) 
{}

Airplane::~Airplane() 
{}

Transport* Airplane::clone() const {
    return new Airplane(*this);
}

void Airplane::print() const {
    std::cout << "Airplane, Airline: " << airlineName << ", Ticket Price: $" << ticketPrice << std::endl;
}

double Airplane::calculatePrice() const {
    return ticketPrice;
}

void Airplane::readFrom(std::istream& is) {
    Transport::readFrom(is);
    is >> ticketPrice;
}



