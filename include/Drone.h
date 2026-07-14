#pragma once

#include "Stop.h"
#include "Position.h"

class Depot;
class Package;
class Route;


class Drone {
    public:
        Drone(int droneId, float droneCapacity, float droneBatteryLife, Position droneCurrentPosition, Depot* droneOriginDepot);
        
        int getId() const;
        float getCapacity() const;
        float getBatteryLife() const;
        Position getCurrentPosition() const;
        Route* getCurrentRoute() const;

        bool addPackage(const Package& package);
        void displayInfo() const;

    private:
        const int id;
        const Package* currentPackage;
        const Depot* originDepot;
        
        float capacity;
        float batteryLife;
        Position currentPosition;
        Route* currentRoute;
    };