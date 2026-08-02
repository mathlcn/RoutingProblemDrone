#pragma once

#include "Task.h"

class Drop : public Task {
    public:
        using Task::Task;
        void executeTask(Drone* drone) override;
        void displayInfo() const override;
};