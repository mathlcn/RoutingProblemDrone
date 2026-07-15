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
        currentStatus = TaskStatus::COMPLETED;
        if (p != nullptr && drone->addPackage(p)) {
            Pickup::setStatus(TaskStatus::COMPLETED);
        }
        else {
            std::cout << "Drone already has a package assigned, cannot pickup package." << std::endl;
            Pickup::setStatus(TaskStatus::PENDING);
            if (p != nullptr) {
                nextStop->addPackage(p);
            }
            drone->getCurrentRoute()->setCurrentStopIndex(drone->getCurrentRoute()->getStops().size() - 1); // Return the drone to the depot by setting the current stop index to the last stop in the route
        }
    }
}

void Pickup::displayInfo() const
{
}