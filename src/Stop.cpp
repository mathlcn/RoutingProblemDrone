#include "Stop.h"
#include "Task.h"
#include <iostream>
#include <vector>

Stop::Stop(int stopId, Position stopPosition)
    : id(stopId), position(stopPosition), packages({}) {}


void Stop::addPackage(Package* package) {
    if (package != nullptr) {
        packages.push_back(package);
    }
}

Package* Stop::removePackage(int packageId) {
    for (std::vector<Package*>::iterator it = packages.begin(); it != packages.end(); ++it) {
        if ((*it)->getId() == packageId) {
            Package* removedPackage = *it;
            packages.erase(it);
            return removedPackage;
        }
    }
    return nullptr;
}





