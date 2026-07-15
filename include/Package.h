#pragma once

class Package {
public:
    explicit Package(int packageId, float packageWeight);

    int getId() const { return id; }
    float getWeight() const { return weight; }

    void displayInfo() const;

private:
    const int id;
    float weight;
};


