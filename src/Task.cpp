#include "Task.h"
#include "Stop.h"
#include "Drone.h"
#include "Package.h"
#include <iostream>
#include <vector>

Task::Task(int taskId, int taskPackageId, std::vector<Stop*> destinations)
    : id(taskId), packageId(taskPackageId), destinations(destinations), status(TaskStatus::PENDING) {}

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
    const std::vector<Stop*>& dest = getDestinations();
    if (dest.empty()) {
        std::cout << "Destinations is empty." << std::endl;
        return;
    }
    for (size_t i = 0; i < dest.size(); i++) {
        std::cout << "Destination " << i << ": ";
        if (dest[i] != nullptr) {
            std::cout << "Stop ID " << dest[i]->getId();
        } else {
            std::cout << "null";
        }
        std::cout << std::endl;
    }
}
