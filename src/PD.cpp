#include "PD.h"
#include "Stop.h"
#include "Drone.h"
#include "Route.h"
#include <iostream>

void PD::executeTask(Drone* drone)
{
    TaskStatus currentStatus = getStatus();
    if (currentStatus == TaskStatus::COMPLETED) {
        std::cout << "Task already completed." << std::endl;
        return;
    }

    Stop* nextStop = drone->getCurrentRoute()->nextStop();
    if (!nextStop) {
        PD::setStatus(TaskStatus::PENDING);
        std::cout << "No more stops in the route." << std::endl;
        return;
    }

    if (currentStatus == TaskStatus::PENDING) {
        std::cout << "Starting PD drop." << std::endl;
        PD::executeDrop(drone, nextStop);
        return;
    }
    if (currentStatus == TaskStatus::DROP_DONE) {
        std::cout << "Starting PD pickup." << std::endl;
        PD::executePickup(drone, nextStop);
        return;
    }
    std::cout << "Something went wrong in PD." << std::endl;
}

void PD::executeDrop(Drone* drone, Stop* nextStop) { 
    Package* p = drone->getCurrentPackage();
    if (!p) {
        PD::setStatus(TaskStatus::PENDING);
        std::cout << "Drone is empty." << std::endl;
        return;
    }
    nextStop->addPackage(p);
    PD::setStatus(TaskStatus::COMPLETED);
    std::cout << "Drop done successfully." << std::endl;
    return;
}

void PD::executePickup(Drone* drone, Stop* nextStop) {
    Package* p = nextStop->removePackage(getPackageId());
    if(!p) {
        PD::setStatus(TaskStatus::DROP_DONE);
        std::cout << "Package doesn't exist." << std::endl;
        return;
    }
    if (drone->getCurrentPackage()) {
        PD::setStatus(TaskStatus::DROP_DONE);
        std::cout << "Drone already has a package." << std::endl;
        return;
    }
    drone->setCurrentPackage(p);
    PD::setStatus(TaskStatus::COMPLETED);
    std::cout << "PD Drop done successfully." << std::endl;
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
