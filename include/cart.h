#pragma once
#include <memory>
#include "customerWrapper.h"
#include "productWrapper.h"
#include "backendService.h"
#include "constants.h"

class Cart
{
private:
	shared_ptr<CustomerWrapper> customer;
	map<shared_ptr<ProductWrapper>, unsigned int> cartItems;
	double non_discountable;
public:
	
	void addCustomer(shared_ptr<CustomerWrapper> c){
		if(customerExists()) throw std::invalid_argument("Customer exists");
		else customer = c;
	};
	void removeCustomer(){customer.reset();};
	bool checkOutValid(){
		if(customer != nullptr) return true;
		return false;
	};
	bool customerExists(){return checkOutValid();};
	void addMembershipToBill(MembershipCategory membership);
	double getTotal();
	void addProduct(shared_ptr<ProductWrapper> product, int qty);

	~Cart();
};

//Exception for cusotmer already added to bill
//Checkout exception
//Product not enough exception
