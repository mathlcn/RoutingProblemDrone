#include "Stop.h"
#include "Task.h"
#include <iostream>
#include <vector>

Stop::Stop(int stopId, Position stopPosition, std::vector<Package> stopPackages)
    : id(stopId), position(stopPosition), packages(stopPackages) {}

int Stop::getId() const {
    return id;
}


void Stop::addPackage(const Package &package) {
    packages.push_back(package);
}

Package* Stop::removePackage(int packageId) {
    for (std::vector<Package>::iterator it = packages.begin(); it != packages.end(); ++it) {
        if (it->getId() == packageId) {
            Package* removedPackage = new Package(*it); // Create a copy of the package to return
            packages.erase(it); // Remove the package from the vector
            return removedPackage; // Return the removed package
        }
    }
    return nullptr; // Return nullptr if the package was not found
}





