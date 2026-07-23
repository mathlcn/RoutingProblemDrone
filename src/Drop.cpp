#include "Drop.h"
#include "Stop.h"
#include "Drone.h"
#include "Route.h"
#include <iostream>

void Drop::executeTask(Drone *drone)
{
    TaskStatus currentStatus = getStatus();
    if (currentStatus == TaskStatus::COMPLETED) {
        std::cout << "Task already completed." << std::endl;
        return;
    }
    
    Stop* nextStop = drone->getCurrentRoute()->nextStop();
    if (nextStop == nullptr) {
        Drop::setStatus(TaskStatus::PENDING);
        std::cout << "No more stops in the route." << std::endl;
        return;
    }

    Package* p = drone->removePackage();
    if (p == nullptr) {
        std::cout << "Package doesn't exist." << std::endl;
        Drop::setStatus(TaskStatus::PENDING);
        return;
    }
    nextStop->addPackage(p);
    Drop::setStatus(TaskStatus::COMPLETED);
}

void Drop::displayInfo() const
{
    std::cout << "Task ID: " << getId() << std::endl;
    std::cout << "Package ID: " << getPackageId() << std::endl;
    std::cout << "Task type: DROP" << std::endl;

    if (getDestinations() != nullptr) {
        std::cout << "Destination Stop ID: " << getDestinations()->getId() << std::endl;
    } else {
        std::cout << "Destination Stop: none" << std::endl;
    }
}