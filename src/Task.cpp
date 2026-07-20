#include "Task.h"
#include "Stop.h"
#include "Drone.h"
#include "Package.h"
#include <iostream>

Task::Task(int taskId, int taskPackageId, int taskStopId)
    : id(taskId), packageId(taskPackageId), dropId(taskStopId), status(TaskStatus::PENDING), destinations(nullptr) {}

void Task::displayInfo() const
{
    std::cout << "Task ID: " << getId() << std::endl;
    std::cout << "Package ID: " << getPackageId() << std::endl;
    std::cout << "Status: ";

    switch (getStatus()) {
        case TaskStatus::PENDING:
            std::cout << "PENDING";
            break;
        case TaskStatus::DROP_DONE:
            std::cout << "DROP_DONE";
            break;
        case TaskStatus::COMPLETED:
            std::cout << "COMPLETED";
            break;
    }

    std::cout << std::endl;

    if (getDestinations() != nullptr) {
        std::cout << "Destination Stop ID: " << getDestinations()->getId() << std::endl;
    } else {
        std::cout << "Destination Stop: none" << std::endl;
    }
}
