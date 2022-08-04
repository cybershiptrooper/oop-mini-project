#pragma once
#include <string>
using namespace std;
#include <memory>
#include "customer.h"
#include "product.h"

class OrderItem{
	private:
		int id;
		shared_ptr<Customer> customer;
        shared_ptr<Product> product;
        int qty;
		char* tm;
        int total;
	public:
        OrderItem(int id,
	        shared_ptr<Customer> customer,
            shared_ptr<Product> product,
            int qty,
            char* tm,
            int total): id(id), customer(customer), product(product), qty(qty), total(total){}
        //getter methods
        int getID();
        shared_ptr<Customer> getCustomer();
        shared_ptr<Product>  getProduct();
        int getQuantity();
        char* getTimeStamp();
        int getTotal();
        //setter methods - mutables for orderItem are quantity and product, everything else will be set in the constructor and can't be edited
        void setQuantity(int qty);
        void setProduct(shared_ptr<Product> product);
};

