#pragma once

#include "Task.h"


class PD : public Task {
    public:
        using Task::Task;
        void executeTask(Drone* drone) override;
        void displayInfo() const override;
    private:
        void executePickup(Drone* drone, Stop* nextStop);
        void executeDrop(Drone* drone, Stop* nextStop);
};