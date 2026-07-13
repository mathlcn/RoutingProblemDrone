#include "Task.h"

int Task::getId() const
{
    return id;
}

int Task::getPackageId() const
{
    return packageId;
}

TaskStatus Task::getStatus() const
{
    return status;
}

void Task::setStatus(TaskStatus newStatus)
{
    status = newStatus;
}

void Task::displayInfo() const
{
    destinations->removePackage(packageId);
}
