#include <iostream>
#include "Product.h"
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


bool testCustomerPipeline(){
	testProductClass();
	// testMembershipClass();
	// testWrapperClass();
	// testManagerClass();
	return true;
}
// bool testWrapperClass(){
// 	string addr = "xyz";
// 	string name = "abc";
// 	char phone[11] = "1234567890";
// 	char phone2[11] = "0987654321";
// 	auto cats = CustomerWrapper::getMembershipCats();
// 	CustomerWrapper wrapper(2, name, addr, phone, cats[2]);
// 	// TODO
// 	return true;
// }
