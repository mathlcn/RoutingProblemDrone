#include "Package.h"
#include <iostream>

Package::Package(int packageId, float packageWeight, int ownerId)
    : id(packageId), weight(packageWeight), owner(ownerId) {}

void Package::displayInfo() const {
    std::cout << "Package ID: " << id << ", Weight: " << weight << " kg" << std::endl;
}

