#include "Drop.h"


void Drop::executeTask(Drone *drone)
{
    TaskStatus currentStatus = getStatus();
    if (currentStatus == TaskStatus::PENDING) {
    }
}

void Drop::displayInfo() const
{
}