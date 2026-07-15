#include "Route.h"
#include "Stop.h"
#include <iostream>
   

Route::Route(const std::vector<Stop*>& routeStops) : stops(routeStops), currentStopIndex(0) {}

Stop* Route::nextStop() {
    if (currentStopIndex >= stops.size() ) {
        return nullptr;
    }
    return stops[currentStopIndex];
}

void Route::displayInfo() const {
    std::cout << "Route Information:" << std::endl;
    for (const Stop *stop : stops) {
        stop->displayInfo();
    }
}