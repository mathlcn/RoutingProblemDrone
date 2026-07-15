#pragma once

#include "Stop.h"
#include <vector>

class Drone;

class Depot : public Stop {
public:
    Depot(int stopId, Position stopPosition, std::vector<Package*> stopPackages);
    void displayInfo() const override;
private:
    std::vector<Drone*> drones;
};
