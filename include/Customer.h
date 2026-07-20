#pragma once

#include <vector>
#include "Stop.h"

class Customer : public Stop {
    public:
        Customer(int customerId, Position customerPosition);

        void displayInfo() const override;
};