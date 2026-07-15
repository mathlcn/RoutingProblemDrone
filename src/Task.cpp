#include "Task.h"
#include "Stop.h"
#include "Drone.h"
#include "Package.h"

void Task::displayInfo() const
{
    destinations->removePackage(packageId);
}
