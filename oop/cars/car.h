#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
protected:
    std::string model; // Model of the car
    bool ev;           // Electric vehicle status
    double range;      // Range in km

public:
    // Constructor
    Car(std::string m, bool e, double r);

    // Virtual destructor
    virtual ~Car() {}

    // Getters
    std::string getModel() const;
    bool isElectric() const;
    double getRange() const;

    // Setters
    void setModel(std::string m);
    void setElectric(bool e);
    void setRange(double r);

    // Virtual display function
    virtual void display() const;
};

#endif