#pragma once
#include <iostream>
#include "orderItem.h"
#include "OrderItemManager.h"
#include <list>
using namespace std;

void OrderItemManager::addItem(shared_ptr<OrderItem> item){
	orderedItems.push_back(item);
}

void OrderItemManager::getListOfOrderedItems(){
    for(auto i:orderedItems){
        cout<<"CustomerName: "<<i->getCustomer()<<
        "Product: "<<i->getProduct()<<
        "QTY: "<<i->getQuantity()<<
        "Total: "<<i->getTotal();
    }
}