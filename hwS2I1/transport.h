#pragma once
#include <iostream>
#include <string>

class Transport {
protected:
    std::string transport_type;

public:
    Transport();
    Transport(std::string type);
    Transport(const Transport& T);
    virtual ~Transport();

    virtual Transport* clone() const abstract;
    virtual void print() const;
    virtual double calculatePrice() const abstract;
    virtual void readFrom(std::istream& is);
    virtual std::string getCarBrand() const abstract;

};

std::istream& operator>>(std::istream& is, Transport& transport);



class Car : public Transport {
private:
    double fuel_consumption;


public:
    Car();
    Car(const std::string& type, double fuel_consumption);
    Car(const Car& C);
    virtual ~Car();

    virtual Transport* clone() const override;
    virtual void print() const override;
    virtual double calculatePrice() const override;
    virtual void readFrom(std::istream& is) override;
    virtual std::string getCarBrand() const override;
};


class Airplane : public Transport {
private:
    std::string airlineName;
    double ticketPrice;

public:
    Airplane();
    Airplane(const std::string& airlineName, double ticketPrice);
    Airplane(const Airplane& A);
    virtual ~Airplane();

    virtual Transport* clone() const override;
    virtual void print() const override;
    virtual double calculatePrice() const override;
    virtual void readFrom(std::istream& is) override;
    virtual std::string getCarBrand() const override;
};
