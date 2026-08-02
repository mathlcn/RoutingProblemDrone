#include "Drone.h"
#include "Depot.h"
#include "Package.h"
#include "Route.h"
#include <iostream>


Drone::Drone(int droneId, float droneCapacity, float droneBatteryLife, Position droneCurrentPosition, Depot *droneOriginDepot)
 : id(droneId), currentPackage(nullptr), originDepot(droneOriginDepot), capacity(droneCapacity), batteryLife(droneBatteryLife), currentPosition(droneCurrentPosition), currentRoute(nullptr) {}


bool Drone::addPackage(Package* package)
{
    if (currentPackage == nullptr && package != nullptr) {
        currentPackage = package;
        return true; // Success
    } else {
        std::cout << "Drone already has a package assigned." << std::endl;
        return false; // Failure
    }
}

Package* Drone::removePackage() {
   Package* p = Drone::getCurrentPackage();
   setCurrentPackage(nullptr);
   return p;
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
