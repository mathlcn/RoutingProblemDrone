#include "Customer.h"
#include <iostream>

void Stop::displayInfo() const {
    std::cout << "Stop ID: " << id << ", Position: (" << position.x << ", " << position.y << ")" << std::endl;
    std::cout << "Packages at this stop:" << std::endl;

    for (const Package* package : packages) {
        if (package != nullptr) {
            package->displayInfo();
        }
    }
}