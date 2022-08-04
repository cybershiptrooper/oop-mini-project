#pragma once
#include <string>

using namespace std;

class Product
{
private:
    string name;
    double cost;

public:
    Product(const string name, const double cost) : name(name), cost(cost) {}
    ~Product() {}
    string getName() { return name; }
    double getCost() { return cost; }
    void updateCost(double newCost) { cost = newCost; }
};


//TODO
//exeption handling for name