#include "customerWrapper.h"
#include <iostream>
map<unsigned int, string> CustomerWrapper::membership_cats = {
	{1, "Classic"},
	{2, "Gold"},
	{3, "Platinum"}
};

CustomerWrapper::CustomerWrapper(
	// const unsigned int ID,
	const string name, const string address, const string phone,
	const string choice): 
		// serialID(ID), 
		customerMembership(NULL),
		customer(make_shared<Customer>(name, address, phone)) {
		if(choice == membership_cats[1]) 
			customerMembership = dynamic_pointer_cast<Membership>(make_shared<ClassicMembership>());
		else if(choice == membership_cats[2]) 
			customerMembership = dynamic_pointer_cast<Membership>(make_shared<GoldMembership>());
		else if(choice == membership_cats[3]) 
			customerMembership = dynamic_pointer_cast<Membership>(make_shared<PlatinumMembership>());
		else cout<<"Please choose an item from the list\n";
}