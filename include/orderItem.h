#pragma once
#include <string>
#include <memory>
#include "customer.h"
#include "productWrapper.h"
#include "time.h"
using namespace std;
class OrderItem{
	private:
		int id;
		shared_ptr<Customer> customer;
        shared_ptr<ProductWrapper> product;
        int qty;
		char* tm;
        int total;
	public:
        OrderItem(int id,
	        shared_ptr<Customer> customer,
            shared_ptr<ProductWrapper> product,
            int qty,
            char* tm): id(id), customer(customer), product(product), qty(qty){}
        //getter methods
        int getID(){return id;};
        shared_ptr<Customer> getCustomer(){return customer;};
        shared_ptr<ProductWrapper>  getProduct(){return product;};
        int getQuantity(){return qty;};
        char* getTimeStamp(){return tm;};
        double getTotal(){return (product->getProduct()->getCost())*qty;};
};
