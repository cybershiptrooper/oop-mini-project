#pragma once
#include <list>
#include <map>
#include"orderItem.h"

class OrderItemManager
{
private:
	list<shared_ptr<OrderItem>> orderedItems; 
	int orderCount = 0;
	OrderItemManager(){};
	OrderItemManager(const OrderItemManager& s) = delete;
	OrderItemManager& operator=(const OrderItemManager& s) = delete;
	
public:
	static OrderItemManager& getInstance(){
		static OrderItemManager OM;
		return OM;
	}
	~OrderItemManager(){};
    // static OrderItemManager& deleteInstance(){};
	void addOrderItem(shared_ptr<OrderItem> item);
	list<shared_ptr<OrderItem>> getListOfOrderedItems(){return orderedItems;};
	int createID(shared_ptr<Customer> customer, shared_ptr<ProductWrapper> product);
	bool checkIfSameAsLastOrder(
		shared_ptr<Customer> customer, 
		shared_ptr<ProductWrapper> product);
};
