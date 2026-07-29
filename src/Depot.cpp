#include "Depot.h"
#include "Drone.h"
#include <iostream>
#include <vector>

Depot::Depot(int stopId, Position stopPosition)
    : Stop(stopId, stopPosition) {}

void Depot::displayInfo() const {
    std::cout << "Depot ID: " << id << ", Position: (" << position.x << ", " << position.y << ")" << std::endl;
    std::cout << "Packages at this depot:" << std::endl;

    for (const Package* package : packages) {
        if (package != nullptr) {
            package->displayInfo();
        }
    }
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