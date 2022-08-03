#include "customerManager.h"

shared_ptr<CustomerWrapper> CustomerManager::searchCustomer(const string phone){
	for(auto c : registeredCustomers){
		string ph= (c->getCustomer())->getPhone();
		if(phone == ph){return c;};
	}
}

void CustomerManager::addCustomer(shared_ptr<CustomerWrapper> customer){
	registeredCustomers.push_back(customer);
	// writeline();
}

void CustomerManager::deleteCustomer(int ID){
	auto it = registeredCustomers.begin();
	unsigned int i = (*it)->getID();
	for(; it != registeredCustomers.end(); it++){
		if((*it)->getID() == ID){
			auto it2 = registeredCustomers.end();
			it2--;//last elem
			swap(*it, *it2);
			break;
		}
		i++;
	}
	int endID = (*it)->getID();
	registeredCustomers.pop_back();
	(*it)->updateID(i);
	//replaceline at ID
	//remove line at end
}

