#pragma once

#include <vector>
#include "Package.h"
#include "Position.h"

class Task;

class Stop {
    public:
        Stop(int stopId, Position stopPosition);
        virtual ~Stop() = default;

        int getId() const { return id; }
        Position getPosition() const { return position; }
        std::vector<Package*> getPackages() const { return packages; }

        void setPosition(Position newPosition) { position = newPosition; }

        void addPackage(Package* package);
        Package* removePackage(int packageId);

        virtual void displayInfo() const = 0;
    protected:
        const int id;
        Position position;
        std::vector<Package*> packages;
};