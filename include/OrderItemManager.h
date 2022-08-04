#pragma once
#include <list>
#include <map>
#include"orderItem.h"

class OrderItemManager
{
private:
	list<shared_ptr<OrderItem>> orderedItems; 
	OrderItemManager(){};
	OrderItemManager(const OrderItemManager& s) = delete;
	OrderItemManager& operator=(const OrderItemManager& s) = delete;
		
public:
	static OrderItemManager& getInstance(){
		static OrderItemManager OM;
		return OM;
	}
	~OrderItemManager(){};
    static OrderItemManager& deleteInstance(){};
	void addItem(shared_ptr<OrderItem> item);
	void getListOfOrderedItems();
};
