#pragma once

#include "Stop.h"
#include "Position.h"

class Depot;
class Package;
class Route;


class Drone {
    public:
        Drone(int droneId, float droneCapacity, float droneBatteryLife, Position droneCurrentPosition, Depot* droneOriginDepot);
        
        int getId() const { return id; }
        float getCapacity() const { return capacity; }
        float getBatteryLife() const { return batteryLife; }
        Position getCurrentPosition() const { return currentPosition; }
        Package* getCurrentPackage() const { return currentPackage; }
        Depot* getOriginDepot() const { return originDepot; }
        Route* getCurrentRoute() const { return currentRoute; }

        void setCurrentPosition(Position newPosition) { currentPosition = newPosition; }
        void setCurrentPackage(Package* package) { currentPackage = package; }
        void setOriginDepot(Depot* depot) { originDepot = depot; }
        void setCurrentRoute(Route* route) { currentRoute = route; }

        bool addPackage(Package* package);
        void displayInfo() const;

    private:
        const int id;
        Package* currentPackage;
        Depot* originDepot;
        
        float capacity;
        float batteryLife;
        Position currentPosition;
        Route* currentRoute;
    };