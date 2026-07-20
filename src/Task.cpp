#include "Task.h"
#include "Stop.h"
#include "Drone.h"
#include "Package.h"
#include <iostream>

Task::Task(int id, int packageId, int dropId) :
    id(id), packageId(packageId), dropId(dropId) {}

void Task::displayInfo() const
{
    std::cout << "Task: " << std::endl;
    std::cout << "id:" << Task::id << ", package: " << Task::packageId << ", dropId: " << Task::dropId << std::endl;

}
