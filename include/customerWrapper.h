#pragma once
#include "customer.h"
#include "membership.h"
#include <memory>
#include <map>

class CustomerWrapper{
	private:
		const unsigned int customerID;
		shared_ptr<Customer> customer;
		// shared_ptr<Membership> customerMembership;
		Membership* customerMembership;
		static map<unsigned int, string> membership_cats;
		
	public:
		CustomerWrapper(
			const string name, const string address, const char* phone,
			const unsigned int ID, const string choice = "None"
		);
		~CustomerWrapper(){delete customerMembership;}
		auto getMembership(){return customerMembership;};
		void setMembership(const string choice);
		auto getCustomer(){return customer;};
};

//Add exception for Membership already defined, choice out of bounds
//Make member smart pointer and use type cast?