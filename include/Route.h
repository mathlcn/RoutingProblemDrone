#pragma once

#include <vector>

class Stop;

class Route {
    public:
        Route(const std::vector<Stop*>& routeStops);

        int getCurrentStopIndex() const;
        std::vector<Stop*> getStops() const;

        void setCurrentStopIndex(int index);

        Stop* nextStop();
        void displayInfo() const;
    private:
        int currentStopIndex = 0;
        std::vector<Stop*> stops;
};