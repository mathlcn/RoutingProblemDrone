#pragma once

#include "TaskStatus.h"

class Stop;
class Drone;
class Package;

class Task {
    public:
        
        Task(int taskId, int taskPackageId, int taskStopId);
        virtual ~Task() = default;
        
        
        int getId() const;
        int getDropId() const;
        int getPackageId() const;
        TaskStatus getStatus() const;
        Stop* getDestinations() const;

        void setStatus(TaskStatus newStatus);

        virtual void executeTask(Drone* drone) = 0;
        virtual void displayInfo() const;

    private:
        const int id;
        const int dropId;
        const int packageId;
        TaskStatus status;
        Stop* destinations;
};