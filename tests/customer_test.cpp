#include <iostream>
#include "customer.h"
#include "customerManager.h"
#include "membership.h"
#include <assert.h>
#include "constants.h"

bool testCustomerClass(){
	cout << "Testing Customer Class\n";
	string addr = "xyz";
	string name = "abc";
	char phone[11] = "1234567890";
	char phone2[11]= "0987654321";
	Customer c(name, addr, phone);

	assert(addr == c.getAddress());
	assert(name == c.getName());
	assert(phone == c.getPhone());

	c.updateAddress(name);
	c.updatePhone(phone2);
	assert(name == c.getAddress());
	assert(phone2 == c.getPhone());
	cout << "Test completed\n";
	return true;
}

bool testMembershipClass(){
	cout << "  Testing Membership Class\n";
	Membership classic = ClassicMembership();
	Membership gold = GoldMembership();
	Membership plat = PlatinumMembership();
	assert(classic.getFees() == 2000);
	assert(classic.getDiscount() == 0.05);
	assert(gold.getFees() == 5000);
	assert(gold.getDiscount() == 0.1);
	assert(plat.getFees() == 10000);
	assert(plat.getDiscount() == 0.15);
	cout << "  Test completed\n";
	return true;
}

bool testWrapperClass(){
	cout << "  Testing Wrapper Class\n";
	string addr = "xyz";
	string name = "abc";
	char phone[11] = "1234567890";
	char phone2[11] = "0987654321";
	// auto cats = CustomerWrapper::getMembershipCats();
	// CustomerWrapper wrapper(2, name, addr, phone, cats[2]);
	CustomerWrapper wrapper(name, addr, phone, ToString(Gold));
	// TODO
	cout << "  Test completed\n";
	return true;
}
bool testParserClass(){
	cout << "  Testing Parser Class\n";
	CustomerParser::getInstance().readFile();
	cout << "  Test completed\n";
	return true;
};
bool testManagerClass(){
	CustomerManager::getInstance();
	// TODO
	return true;
}

bool testCustomerPipeline(){
	testCustomerClass();
	testMembershipClass();
	testWrapperClass();
	testManagerClass();
	testParserClass();
	return true;
}