#pragma once

#include "TaskStatus.h"

class Stop;
class Drone;
class Package;

class Task {
    public:
        
        Task(int taskId, int taskPackageId, int taskStopId);
        virtual ~Task() = default;
        
        
        int getId() const { return id; }
        int getDropId() const { return dropId; }
        int getPackageId() const { return packageId; }
        TaskStatus getStatus() const { return status; }
        Stop* getDestinations() const { return destinations; }

        void setStatus(TaskStatus newStatus) { status = newStatus; }
        void setDestinations(Stop* newDestinations) { destinations = newDestinations; }

        virtual void executeTask(Drone* drone) = 0;
        virtual void displayInfo() const;

    private:
        const int id;
        const int dropId;
        const int packageId;
        TaskStatus status;
        Stop* destinations;
};