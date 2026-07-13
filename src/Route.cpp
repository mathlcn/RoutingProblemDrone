#include "Route.h"
#include <iostream>
   

Route::Route(const std::vector<Stop *> &routeStops)
: stops(routeStops) {}

int Route::getCurrentStopIndex() const {
    return currentStopIndex;
}

std::vector<Stop*> Route::getStops() const {
    return stops;
}

void Route::setCurrentStopIndex(int index) {
    currentStopIndex = index;
}

Stop* Route::nextStop() {
    if (currentStopIndex < stops.size()) {
        return stops[currentStopIndex++];
    } else {
        return nullptr; // No more stops in the route
    }
}

void Route::displayInfo() const {
    std::cout << "Route Information:" << std::endl;
    for (const Stop *stop : stops) {
        stop->displayInfo();
    }
}