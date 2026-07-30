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
    drone->setCurrentPosition(nextStop->getPosition()); // drone fly

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

    const std::vector<Stop*> dest = getDestinations();
    if (!dest.empty() && dest[0] != nullptr) {
        std::cout << "Destination Stop ID: " << dest[0]->getId() << std::endl;
    } else {
        std::cout << "Destination Stop: none" << std::endl;
    }
}