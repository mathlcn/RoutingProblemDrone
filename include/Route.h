#pragma once

#include <vector>
#include "Stop.h"

class Route {
    public:
        Route(const std::vector<Stop*>& routeStops);

        int getCurrentStopIndex() const { return currentStopIndex; }
        std::vector<Stop*> getStops() const { return stops; }

        void setCurrentStopIndex(int index) { currentStopIndex = index; }

        Stop* nextStop();
        void displayInfo() const;
    private:
        int currentStopIndex = 0;
        std::vector<Stop*> stops;
};