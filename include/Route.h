#pragma once

#include <vector>

class Stop;

class Route {
    public:
        Route(const std::vector<Stop*>& routeStops);

        int getCurrentStopIndex() const { return currentStopIndex; }
        std::vector<Stop*> getStops() const { return stops; }

        void setCurrentStopIndex(int index) { currentStopIndex = index; }
        void setStops(const std::vector<Stop*>& newStops) { stops = newStops; }

        Stop* nextStop();
        void displayInfo() const;
    private:
        int currentStopIndex = 0;
        std::vector<Stop*> stops;
};