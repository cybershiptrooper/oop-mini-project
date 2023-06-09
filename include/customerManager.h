#pragma once
#include "customerWrapper.h"
#include <list>
#include "customerParser.h"

class CustomerManager
{
private:
	list<shared_ptr<CustomerWrapper>> registeredCustomers; 
	CustomerManager(){};
	CustomerManager(const CustomerManager& s) = delete;
	CustomerManager& operator=(const CustomerManager& s) = delete;
	
public:
	static CustomerManager& getInstance(){
		static CustomerManager CM;
		return CM;
	}
	shared_ptr<CustomerWrapper> searchCustomer(const string phone);//exception for phone
	void deleteCustomer(string phone);
	void addCustomer(shared_ptr<CustomerWrapper> customer);
	auto getCustomerList(){return registeredCustomers;};

};
