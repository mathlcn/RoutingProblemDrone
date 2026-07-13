#pragma once

class Package {
public:explicit Package(int packageId,float packageWeight);

    int getId() const;

    void displayInfo() const;

private:
    const int id;
    float weight;
};


