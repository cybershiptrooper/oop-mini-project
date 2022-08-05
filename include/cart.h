#pragma once
#include <memory>
#include "customerWrapper.h"
#include "productWrapper.h"
class Cart
{
private:
	weak_ptr<CustomerWrapper> customer;
	map<weak_ptr<ProductWrapper>, unsigned int> cartItems;
	double non_discountable;
public:
	
	bool addCustomer(weak_ptr<CustomerWrapper> c){
		if(customer.lock()){return false;}
		customer = c;
		return true;
	};
	void removeCustomer(){customer.reset();};
	bool checkOutValid(){
		if(!customer.lock()) return true;
		return false;
	};
	bool addMembershipToBill();
	bool getTotal(){/*TODO*/};
	bool addProduct(weak_ptr<Product>, int qty){/*TODO*/};

	~Cart();
};

//Exception for cusotmer already added to bill
//Checkout exception
//Product not enough exception
