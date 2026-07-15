#include "Depot.h"
#include "Drone.h"
#include <iostream>
#include <vector>

Depot::Depot(int stopId, Position stopPosition, std::vector<Package*> stopPackages)
    : Stop(stopId, stopPosition, stopPackages) {}

void Depot::displayInfo() const {
    Stop::displayInfo();
    std::cout << "This is a depot." << std::endl;
}
