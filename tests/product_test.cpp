#include <iostream>
#include "Product.h"
#include <assert.h>

bool testProductClass(){
	cout << "Testing Product Class\n";
	double id = 123;
	string name = "abc";
    double cost = 500;
    string category = "food";
	
	Product p1(id, name, cost, category);


	assert(id == p1.getID());
	assert(name == p1.getName());
	assert(cost == p1.getCost());
    p1.updateCost(200);
    assert(200 == p1.getCost());

    Product p2(232, "xyz", 200, "food");
    assert(p1.getCategoryNum()==p2.getCategoryNum());
	
	cout << "Test completed\n";
	return true;
}