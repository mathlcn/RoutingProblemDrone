#pragma once

#include "Task.h"

class Pickup : public Task {
    void executeTask(Drone* drone) override;
    void displayInfo() const override;
};