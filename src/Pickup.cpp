#include "Pickup.h"
#include "Drone.h"
#include "Stop.h"
#include "Route.h"
#include <iostream>

void Pickup::executeTask(Drone *drone)
{
    TaskStatus currentStatus = getStatus();
    if (currentStatus == TaskStatus::PENDING || currentStatus == TaskStatus::DROP_DONE) {
        Stop* nextStop = drone->getCurrentRoute()->nextStop();
        if (nextStop == nullptr) {
            currentStatus = TaskStatus::PENDING;
            std::cout << "No more stops in the route, cannot pickup package." << std::endl;
            return;
        }

        Package* p = nextStop->removePackage(getPackageId());

        if (p == nullptr) {
            std::cout << "Package doesn't exist." << std::endl;
            Pickup::setStatus(TaskStatus::PENDING);
            return;
        }
        if (drone->addPackage(p)) {
            Pickup::setStatus(TaskStatus::COMPLETED);
            return;
        }
        std::cout << "Drone already has a package assigned, cannot pickup package." << std::endl;
        Pickup::setStatus(TaskStatus::PENDING);
        nextStop->addPackage(p);
        drone->getCurrentRoute()->setCurrentStopIndex(drone->getCurrentRoute()->getStops().size() - 1); // Return the drone to the depot by setting the current stop index to the last stop in the route
    }
}

void Pickup::displayInfo() const
{
    std::cout << "Task ID: " << getId() << std::endl;
    std::cout << "Package ID: " << getPackageId() << std::endl;
    std::cout << "Pickup task" << std::endl;

    if (getDestinations() != nullptr) {
        std::cout << "Destination Stop ID: " << getDestinations()->getId() << std::endl;
    } else {
        std::cout << "Destination Stop: none" << std::endl;
    }
}