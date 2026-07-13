#include "Package.h"
#include <iostream>

Package::Package(int packageId, float packageWeight)
    : id(packageId), weight(packageWeight) {}

int Package::getId() const {
    return id;
}

void Package::displayInfo() const {
    std::cout << "Package ID: " << id << ", Weight: " << weight << " kg" << std::endl;
}

