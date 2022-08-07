#pragma once
#include "customer.h"
#include "membership.h"
#include <memory>
#include <map>

class CustomerWrapper{
	private:
		// unsigned int serialID;
		shared_ptr<Customer> customer;
		shared_ptr<Membership> customerMembership;
		// Membership* customerMembership;
		
	public:
		CustomerWrapper(
			// const unsigned int ID,
			const string name, const string address, const string phone,
			const string choice = "No"
		);
		~CustomerWrapper(){};//{delete customerMembership;}
		auto getMembership(){return customerMembership;};
		void setMembership(const string choice);
		auto getCustomer(){return customer;};
		// static map<unsigned int, string> getMembershipCats(){return CustomerWrapper::membership_cats;};
		// unsigned int getID(){return serialID;};
		// void updateID(int ID){serialID = ID;};
};

//Add exception for Membership already defined, choice out of bounds
//Make member smart pointer and use type cast?
//Changing serialID is bad: improve it