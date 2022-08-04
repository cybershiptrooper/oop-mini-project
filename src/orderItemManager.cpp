#pragma once
#include <iostream>
#include "orderItem.h"
#include "orderItemManager.h"
#include <list>
using namespace std;

void OrderItemManager::addOrderItem(shared_ptr<OrderItem> item){
	orderedItems.push_back(item);
}
