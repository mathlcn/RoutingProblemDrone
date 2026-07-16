#include "Depot.h"
#include "Drone.h"
#include <iostream>
#include <vector>

Depot::Depot(int stopId, Position stopPosition, std::vector<Package*> stopPackages)
    : Stop(stopId, stopPosition) {}

void Depot::displayInfo() const {
    Stop::displayInfo();
    std::cout << "This is a depot." << std::endl;
}

void Depot::addDrone(Drone* drone) {
    if (drone)
        drones.push_back(drone);
}

Drone* Depot::removeDrone(int droneId) {
    for (std::vector<Drone*>::iterator it = drones.begin(); it != drones.end(); ++it) {
        if ((*it)->getId() == droneId) {
            Drone* removedDrone = *it;
            drones.erase(it);
            return removedDrone;
        }
    }
    return nullptr;
}