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
		time_t tm;
        int total;
	public:
        OrderItem(int id,
	        shared_ptr<Customer> customer,
            shared_ptr<ProductWrapper> product,
            int qty,
            time_t tm): id(id), customer(customer), product(product), qty(qty), tm(tm){}
        //getter methods
        int getID(){return id;};
        shared_ptr<Customer> getCustomer(){return customer;};
        shared_ptr<ProductWrapper>  getProduct(){return product;};
        int getQuantity(){return qty;};
        time_t getTimeStamp(){return tm;};
        double getTotal(){return (product->getProduct()->getCost())*qty;};
};
