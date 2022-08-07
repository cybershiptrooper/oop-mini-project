#pragma once
#include <memory>
#include <map>
#include <iostream>
#include <assert.h>
#include <string>
#include "customerWrapper.h"
#include "productWrapper.h"
#include "backendService.h"
#include "constants.h"

class Cart
{
private:
	shared_ptr<CustomerWrapper> customer;
	shared_ptr<ProductWrapper> membershipProd;
	map<shared_ptr<ProductWrapper>, unsigned int> cartItems;
	MembershipCategory boughtMembership;
	double non_discountable;
public:
	Cart(): customer(nullptr), non_discountable(0), boughtMembership(No){};
	void addCustomer(shared_ptr<CustomerWrapper> c){
		if(customerExists()) throw std::invalid_argument("Customer exists");
		else customer = c;
	};
	void removeCustomer(){customer.reset();};
	bool cartEmpty(){
		if( ((cartItems.empty())) and (boughtMembership == No) ) return true;
		return false;
	};
	bool customerExists(){return (customer!=nullptr);};
	bool checkOutValid(){
		if((customerExists()) and
		 (not cartEmpty())) return true;
		return false;
	};
	void removeMembershipFromBill(){
		boughtMembership = No;
		removeProductFromCart(membershipProd);
		membershipProd.reset();
	};
	void addMembershipToBill(MembershipCategory membership);
	double getTotal();
	double getDiscount();
	void addProduct(shared_ptr<ProductWrapper> product, int qty);
	bool productInCart(shared_ptr<ProductWrapper> product);
	void removeProductFromCart(shared_ptr<ProductWrapper> product);
	auto& getCartItems() const{return cartItems;};
	auto& getCustomer(){return customer;}
	double checkout();
};

//Exception for cusotmer already added to bill
//Checkout exception
//Product not enough exception
