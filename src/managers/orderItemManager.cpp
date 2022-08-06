#include <iostream>
#include "orderItem.h"
#include "orderItemManager.h"
#include <list>
#include <assert.h>
using namespace std;

void OrderItemManager::addOrderItem(shared_ptr<OrderItem> item){
	orderedItems.push_back(item);
}

int OrderItemManager::createID(shared_ptr<Customer> customer, shared_ptr<Product> product){
	if(checkIfSameAsLastOrder(customer, product)){ 
		assert(orderedItems.back()->getID() == orderCount);
		return (orderCount);
	}
	return (++orderCount);
}

bool OrderItemManager::checkIfSameAsLastOrder(
	shared_ptr<Customer> customer, shared_ptr<Product> product){
	if(orderCount == 0) return false;
	bool ans = false;
	if(
		(customer->getPhone() == customer->getPhone())
		or (product->getName() == product->getName())
	) ans = true;
	return ans;
}