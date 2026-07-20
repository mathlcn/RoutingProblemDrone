#include "Customer.h"
#include <iostream>

Customer::Customer(int customerId, Position customerPosition) 
: Stop(customerId, customerPosition) {}

void Customer::displayInfo() const {
    std::cout << "Customer ID: " << id << ", Position: (" << position.x << ", " << position.y << ")" << std::endl;
    std::cout << "Packages at this customer:" << std::endl;

    for (const Package* package : packages) {
        if (package != nullptr) {
            package->displayInfo();
        }
    }
}