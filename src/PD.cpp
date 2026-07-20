#include "PD.h"
#include "Stop.h"
#include <iostream>

void PD::executeTask(Drone* drone)
{
    (void)drone;
}

void PD::displayInfo() const
{
    std::cout << "Task ID: " << getId() << std::endl;
    std::cout << "Package ID: " << getPackageId() << std::endl;
    std::cout << "Task type: PD" << std::endl;

    if (getDestinations() != nullptr) {
        std::cout << "Destination Stop ID: " << getDestinations()->getId() << std::endl;
    } else {
        std::cout << "Destination Stop: none" << std::endl;
    }
}
