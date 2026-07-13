#pragma once

#include "Package.h"
#include "Stop.h"
#include "Drone.h"
#include "TaskStatus.h"



class Task {
    public:
        
        Task(int taskId, int taskPackageId, int taskStopId);
        virtual ~Task() = default;
        
        
        int getId() const;
        int getPackageId() const;
        Stop nextStop() const;    
        TaskStatus getStatus() const;
        void setStatus(TaskStatus newStatus);
        virtual void executeTask(Drone* drone);
        virtual void displayInfo() const;

    private:
        const int id;
        const int dropId;
        int packageId;
        TaskStatus status;
        Stop* destinations;
};