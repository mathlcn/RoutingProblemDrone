#include <vector>
#include "Customer.h"


int main() {
    Position stopPosition = {10.0f, 20.0f};

    Customer c1(1, stopPosition);
    Package package1(1, 5.0f, c1.getId());
    Package package2(2, 3.5f, c1.getId());
    c1.addPackage(&package1);
    c1.addPackage(&package2);

    c1.displayInfo();
    return 0;
}