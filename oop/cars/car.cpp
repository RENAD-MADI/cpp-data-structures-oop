#include "car.h"
#include <iostream>

// Constructor implementation
Car::Car(std::string m, bool e, double r) : model(m), ev(e), range(r) {}

// Getters implementation
std::string Car::getModel() const { return model; }
bool Car::isElectric() const { return ev; }
double Car::getRange() const { return range; }

// Setters implementation
void Car::setModel(std::string m) { model = m; }
void Car::setElectric(bool e) { ev = e; }
void Car::setRange(double r) { range = r; }

// Virtual display function implementation
void Car::display() const {
    std::cout << "Model: " << model << "\n";
    std::cout << "Electric Vehicle: " << (ev ? "Yes" : "No") << "\n";
    std::cout << "Range: " << range << " km\n";
}
