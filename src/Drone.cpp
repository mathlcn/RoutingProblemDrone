#include "Drone.h"
#include <iostream>


Drone::Drone(int droneId, float droneCapacity, float droneBatteryLife, Position droneCurrentPosition, Depot *droneOriginDepot)
 : id(droneId), capacity(droneCapacity), batteryLife(droneBatteryLife), currentPosition(droneCurrentPosition), originDepot(droneOriginDepot){}


int Drone::getId() const
{
    return id;
}

float Drone::getCapacity() const
{
    return capacity;
}

float Drone::getBatteryLife() const
{
    return batteryLife;
}

Position Drone::getCurrentPosition() const
{
    return currentPosition;
}

Route* Drone::getCurrentRoute() const
{
    return currentRoute;
}


bool Drone::addPackage(const Package& package)
{
    if (currentPackage == nullptr) {
        currentPackage = &package;
        return true; // Success
    } else {
        std::cout << "Drone already has a package assigned." << std::endl;
        return false; // Failure
    }
}

void Drone::displayInfo() const
{
    std::cout << "Drone ID: " << id << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Battery Life: " << batteryLife << std::endl;
    std::cout << "Current Position: (" << currentPosition.x << ", " << currentPosition.y << ")" << std::endl;
    if (currentPackage) {
        currentPackage->displayInfo();
    } else {
        std::cout << "No package assigned." << std::endl;
    }
    if (originDepot) {
        originDepot->displayInfo();
    } else {
        std::cout << "No origin depot assigned." << std::endl;
    }
}
