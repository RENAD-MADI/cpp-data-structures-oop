#include "ev.h"
#include <iostream>

// Constructor implementation
EV::EV(std::string m, bool e, double r, std::string mk, int y)
    : Car(m, e, r), make(mk), makeYear(y) {}

// Getters implementation
std::string EV::getMake() const { return make; }
int EV::getMakeYear() const { return makeYear; }

// Setters implementation
void EV::setMake(std::string mk) { make = mk; }
void EV::setMakeYear(int y) { makeYear = y; }

// Overridden display function implementation
void EV::display() const {
    Car::display(); // Call base class display
    std::cout << "Make: " << make << "\n";
    std::cout << "Make Year: " << makeYear << "\n";
}
