#pragma once

#include "Task.h"

class PD : public Task {
    public:
        void executeTask(Drone* drone) override;
        void displayInfo() const override;
};