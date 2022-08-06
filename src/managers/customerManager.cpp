#include "customerManager.h"

shared_ptr<CustomerWrapper> CustomerManager::searchCustomer(const string phone){
	for(auto c : registeredCustomers){
		string ph= (c->getCustomer())->getPhone();
		if(phone == ph){return c;};
	}
	return nullptr;
}

void CustomerManager::addCustomer(shared_ptr<CustomerWrapper> customer){
	registeredCustomers.push_back(customer);
	// writeline();
}

void CustomerManager::deleteCustomer(string phone){
	auto it = registeredCustomers.begin();
	// unsigned int i = (*it)->getID();
	for(; it != registeredCustomers.end(); it++){
		if((*it)->getCustomer()->getPhone() == phone){
			// auto it2 = registeredCustomers.end();
			// it2--;//last elem
			registeredCustomers.erase(it);
			break;
		}
		// i++;
	}
	// int endID = (*it)->getID();
	registeredCustomers.pop_back();
	// (*it)->updateID(i);
	//replaceline at ID
	//remove line at end
}

