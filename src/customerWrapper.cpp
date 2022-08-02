#include "customerWrapper.h"
#include <iostream>
map<unsigned int, string> CustomerWrapper::membership_cats = {
	{1, "Classic"},
	{2, "Gold"},
	{3, "Platinum"}
};

CustomerWrapper::CustomerWrapper(
	const string name, const string address, const char* phone,
	const unsigned int ID,
	const string choice): 
		customerID(ID), customerMembership(NULL),
		customer(make_shared<Customer>(name, address, phone)) {
		if(choice == membership_cats[1]) customerMembership = new ClassicMembership();
		else if(choice == membership_cats[2]) customerMembership = new GoldMembership();
		else if(choice == membership_cats[3]) customerMembership = new PlatinumMembership();
		else cout<<"Please choose an item from the list\n";
}