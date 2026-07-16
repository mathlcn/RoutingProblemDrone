#pragma once

#include "Stop.h"
#include <vector>

class Drone;

class Depot : public Stop {
public:
    Depot(int stopId, Position stopPosition, std::vector<Package*> stopPackages);

    std::vector<Drone*> getDrones() const;
    void addDrone(Drone* drone);
    Drone* removeDrone(int droneId);

    void displayInfo() const override;
private:
    std::vector<Drone*> drones;
};
