#pragma once

class Package {
public:
    explicit Package(int packageId, float packageWeight, int ownerId);

    int getId() const { return id; }
    float getWeight() const { return weight; }

    void displayInfo() const;

private:
    const int id;
    const int owner;
    float weight;
    
};


