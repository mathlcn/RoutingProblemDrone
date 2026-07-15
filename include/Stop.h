#pragma once

#include <vector>
#include "Package.h"
#include "Position.h"

class Task;

class Stop {
    public:
        Stop(int stopId, Position stopPosition, std::vector<Package*> stopPackages);
        virtual ~Stop() = default;

        int getId() const { return id; }
        Position getPosition() const { return position; }
        std::vector<Package*> getPackages() const { return packages; }
        Stop* getNextStop() const { return nextStop; }

        void addPackage(Package* package);
        Package* removePackage(int packageId);

        void setPosition(Position newPosition) { position = newPosition; }
        void setPackages(const std::vector<Package*>& newPackages) { packages = newPackages; }

        virtual void displayInfo() const;
    
    protected:
        const int id;
        Position position;
        std::vector<Package*> packages;
        Stop* nextStop = nullptr;
};