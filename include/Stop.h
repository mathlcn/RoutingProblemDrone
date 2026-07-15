#pragma once

#include <vector>
#include "Package.h"
#include "Position.h"

class Task;

class Stop {
    public:
        Stop(int stopId, Position stopPosition, std::vector<Package*> stopPackages);
        virtual ~Stop() = default;

        int getId() const;

        void addPackage(Package* package);
        Package* removePackage(int packageId);
        Stop* getNextStop() const;

        Task* createTask(int packageId) const;

        virtual void displayInfo() const;
    
    protected:
        const int id;
        Position position;
        std::vector<Package*> packages;
};