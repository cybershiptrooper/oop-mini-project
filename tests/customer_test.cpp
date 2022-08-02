#include <iostream>
#include "customer.h"
#include <assert.h>

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