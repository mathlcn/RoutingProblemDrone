#pragma once

#include "Task.h"

class Drop : public Task {
    public:
        void executeTask(Drone* drone) override;
        void displayInfo() const override;
};