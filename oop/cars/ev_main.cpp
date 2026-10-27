#include "ev.h"

int main() {
    // Create an EV object
    EV myEV("Hyundai Kona", true, 300.5, "Hyundai", 2024);

    // Display EV details
    myEV.display();

    // Update EV details
    myEV.setModel("Tesla Model 3");
    myEV.setElectric(true);
    myEV.setRange(500.0);
    myEV.setMake("Tesla");
    myEV.setMakeYear(2023);

    // Display updated EV details
    myEV.display();

    return 0;
}
