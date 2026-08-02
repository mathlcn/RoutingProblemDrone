#pragma once

#include "Task.h"

class Pickup : public Task {
    public:
        using Task::Task;
        void executeTask(Drone* drone) override;
        void displayInfo() const override;
};