#include <vector>
#include "Stop.h"


int main() {
    Position stopPosition = {10.0f, 20.0f};
    Package package1(1, 5.0f);
    Package package2(2, 3.5f);
    std::vector<Package*> stopPackages = {&package1, &package2};
    Stop stop(1, stopPosition, stopPackages);
    stop.displayInfo();
    return 0;
}