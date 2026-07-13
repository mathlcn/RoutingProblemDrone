#include "Drop.h"


void Drop::executeTask(Drone *drone)
{
    TaskStatus currentStatus = getStatus();
    if (currentStatus == TaskStatus::PENDING) {
        Package* p = nextStop().removePackage(getPackageId());
    }
}

void Drop::displayInfo() const
{
}