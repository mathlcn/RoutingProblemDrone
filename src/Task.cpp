#include "Task.h"
#include "Stop.h"
#include "Drone.h"
#include "Package.h"

int Task::getId() const
{
    return id;
}

int Task::getDropId() const
{
    return dropId;
}

int Task::getPackageId() const
{
    return packageId;
}

TaskStatus Task::getStatus() const
{
    return status;
}

Stop* Task::getDestinations() const
{
    return destinations;
}

void Task::setStatus(TaskStatus newStatus)
{
    status = newStatus;
}



void Task::displayInfo() const
{
    destinations->removePackage(packageId);
}
