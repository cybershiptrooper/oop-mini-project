#include "customerWrapper.h"
#include <iostream>
#include "constants.h"

// map<unsigned int, string> CustomerWrapper::membership_cats = 
std::map<int, std::string> memberCategoryMap = {
	{1, "Classic"},
	{2, "Gold"},
	{3, "Platinum"},
	{4, "No"}
};
CustomerWrapper::CustomerWrapper(
	// const unsigned int ID,
	const string name, const string address, const string phone,
	const string choice):  
		customerMembership(NULL),
		customer(make_shared<Customer>(name, address, phone)) {
			setMembership(choice);	
}

void CustomerWrapper::setMembership(const string choice){
	customerMembership.reset();
	if(choice == ToString(Classic)) 
		customerMembership = dynamic_pointer_cast<Membership>(make_shared<ClassicMembership>());
	else if(choice == ToString(Gold)) 
		customerMembership = dynamic_pointer_cast<Membership>(make_shared<GoldMembership>());
	else if(choice == ToString(Platinum)) 
		customerMembership = dynamic_pointer_cast<Membership>(make_shared<PlatinumMembership>());
	else
		customerMembership = dynamic_pointer_cast<Membership>(make_shared<NoMembership>());
	// else throw choice;
}