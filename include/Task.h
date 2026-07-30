#pragma once

#include "TaskStatus.h"
#include <vector>

class Stop;
class Drone;
class Package;

class Task {
    public:
        
        Task(int taskId, int taskPackageId, std::vector<Stop*> taskStop);
        virtual ~Task() = default;
        
        
        int getId() const { return id; }
        int getPackageId() const { return packageId; }
        TaskStatus getStatus() const { return status; }
        std::vector<Stop*> getDestinations() const { return destinations; }

        void setStatus(TaskStatus newStatus) { status = newStatus; }
        void setDestinations(std::vector<Stop*> newDestinations) { destinations = newDestinations; }

        virtual void executeTask(Drone* drone) = 0;
        virtual void displayInfo() const = 0;

    private:
        const int id;
        const int packageId;
        TaskStatus status;
        std::vector<Stop*> destinations;
};