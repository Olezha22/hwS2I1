#pragma once
#include "travel.h"
#include "transport.h"

class CarContainer {
private:
    CarTravel** carTravels;
    int size;
public:
    CarContainer();
    CarContainer(int n, CarTravel** CT);
    ~CarContainer();

    void addCarTravel();
    void printCarTravels() const;
    const Transport* getCarFromHighest() const;
};

class AirContainer {
private:
    AirTravel** airTravels;
    int size;
public:
    AirContainer();
    AirContainer(int n, AirTravel** AT);
    ~AirContainer();

    void addAirTravel();
    void printAirTravels() const;
    int findCheapMembers() const;
};
