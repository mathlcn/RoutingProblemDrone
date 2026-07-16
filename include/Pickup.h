#pragma once

#include "Task.h"

class Pickup : public Task {
    public:
        void executeTask(Drone* drone) override;
        void displayInfo() const override;
};