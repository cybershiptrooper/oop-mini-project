
#include <string>
#include<map>
using namespace std;

class Product
{
    double ID;
    string name;
    double cost;
    string category;
    static map<string, int> category_map;

public:
    Product(double ID, string name, double cost, string category) : ID(ID), name(name), cost(cost), category(category)
    {
        if (category_map.find(category)==category_map.end())
        {
            category_map[category] = category_map.size();
        }
    }
    ~Product() {}
    string getName() { return name; }
    double getID() { return ID; }
    double getCost() { return cost; }
    void updateCost(double newCost) { cost = newCost; }
    int getCategoryNum(){
       return category_map[category];
    }
};

map<string, int> Product::category_map = map<string, int>();

// TODO
// category int mapping