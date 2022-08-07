#include <iostream>
#include "orderItem.h"
#include "orderItemManager.h"
#include <list>
#include <assert.h>
using namespace std;

void OrderItemManager::addOrderItem(shared_ptr<OrderItem> item){
	orderedItems.push_back(item);
}

int OrderItemManager::createID(
	shared_ptr<Customer> customer, 
	shared_ptr<ProductWrapper> product){
	if(checkIfSameAsLastOrder(customer, product)){ 
		assert(orderedItems.back()->getID() == orderCount);
		return (orderCount);
	}
	return (++orderCount);
}

bool OrderItemManager::checkIfSameAsLastOrder(
	shared_ptr<Customer> customer, shared_ptr<ProductWrapper> product){
	if(orderCount == 0) return false;
	auto last = orderedItems.back();
	bool ans = false;
	if(
		(customer->getPhone() == last->getCustomer()->getPhone())
		and (*product == *(last->getProduct()))
	) ans = true;
	return ans;
}