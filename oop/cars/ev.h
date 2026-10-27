#ifndef EV_H
#define EV_H

#include "car.h"
#include <string>

class EV : public Car {
private:
    std::string make; // Make of the EV
    int makeYear;     // Year of make

public:
    // Constructor
    EV(std::string m, bool e, double r, std::string mk, int y);

    // Getters
    std::string getMake() const;
    int getMakeYear() const;

    // Setters
    void setMake(std::string mk);
    void setMakeYear(int y);

    // Overridden display function
    void display() const override;
};

#endif
