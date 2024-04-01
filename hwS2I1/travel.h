#pragma once
#include "transport.h"

class Travel {
protected:
    Transport* transport;
    std::string destination;

public:
    Travel();
    Travel(Transport* transport, const std::string& destination);
    Travel(const Travel& T);
    virtual ~Travel();

    virtual double calculatePrice() const abstract;
    virtual void print() const;
    virtual void readFrom(std::istream& is);
    const Transport* getTransport() const;
};

std::istream& operator>>(std::istream& is, Travel& T);


class CarTravel : public Travel {
private:
    double distance;

public:
    CarTravel();
    CarTravel(Transport* transport, const std::string& destination, double distance);
    CarTravel(const CarTravel& Ñ);
    virtual ~CarTravel();

    virtual double calculatePrice() const override;
    virtual void print() const override;
    virtual void readFrom(std::istream& is) override;
    double getDistance() const;
    

};


class AirTravel : public Travel {
private:
    int familyMembers;

public:
    AirTravel();
    AirTravel(Transport* transport, const std::string& destination, int familyMembers);
    AirTravel(const AirTravel& A);
    virtual ~AirTravel();

    virtual double calculatePrice() const override;
    virtual void print() const override;
    virtual void readFrom(std::istream& is) override;
    int getFamilyMembers() const;

};




void readTravelsFromFile(const std::string& filename, Travel**& travels, int& n);

void calculateCosts(Travel** travels, int n, double& totalCost, double& maxCar, double& maxAir);

void printResults(Travel** travels, int n, double totalCost, double maxCar, double maxAir);

//void writeToContainers(const std::string& filename, CarContainer& carContainer, AirContainer& airContainer, int& n);