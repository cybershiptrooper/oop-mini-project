#include <iostream>
#include "product.h"
#include "productManager.h"
#include <assert.h>

bool testProductClass()
{
	cout << "Testing Product Class\n";
	string name = "xyz";
	double cost = 200;
	double newcost = 300;
	Product c(name, cost);

	assert(name == c.getName());
	assert(cost == c.getCost());

	c.updateCost(newcost);
	assert(newcost == c.getCost());
	cout << "Test completed\n";
	return true;
}

bool testProdWrapperClass(){

	string name = "abc";
	double cost = 300;
	string cat = "food";
	int stock = 5;
	ProductWrapper pw(name, cost, cat, stock);
	assert(stock == pw.getStock());
	auto prod = pw.getProduct();
	assert(name == prod->getName());
	return true;
}

bool testProdManagerClass(){
	string name = "abc";
	double cost = 300;
	string cat = "food";
	int stock = 5;
	ProductManager &PM = ProductManager::getInstance();

	PM.addProduct(make_shared<ProductWrapper>(name, cost, cat, stock));
	auto p = PM.searchProduct(name);
	// PM.DisplayProduct(p);
	assert(p->getProduct()->getName() == name);
	return true;

}

bool testProductPipeline(){
	testProductClass();
	testProdWrapperClass();
	testProdManagerClass();
	return true;
}
