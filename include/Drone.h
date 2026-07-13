#pragma once

#include "Depot.h"
#include "Stop.h"
#include "Package.h"
#include "Route.h"
#include "Position.h"


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