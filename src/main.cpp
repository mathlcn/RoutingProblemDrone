#include <vector>
#include "Stop.h"


int main() {
    Position stopPosition = {10.0f, 20.0f};
    Package package1(1, 5.0f);
    Package package2(2, 3.5f);
    Stop stop(1, stopPosition);
    stop.addPackage(&package1);
    stop.addPackage(&package2);
    stop.displayInfo();
    return 0;
}