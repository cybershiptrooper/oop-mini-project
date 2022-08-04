#pragma once
#include <string>
using namespace std;
#include "customer.h"
#include "Product.h"

class OrderItem{
	private:
		int id;
		Customer* customer;
        Product* product;
        int qty;
		char* tm;
        int total;
	public:
        OrderItem(int id,
	        Customer* customer,
            Product* product,
            int qty,
            char* tm,
            int total);
        //getter methods
        int getID();
        Customer* getCustomer();
        Product* getProduct();
        int getQuantity();
        char* getTimeStamp();
        int getTotal();
        //setter methods - mutables for orderItem are quantity and product, everything else will be set in the constructor and can't be edited
        void setQuantity(int qty);
        void setProduct(Product* product);
};

