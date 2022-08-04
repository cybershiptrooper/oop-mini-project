#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include "customer.h"
#include "orderItem.h"
#include "Product.h"
using namespace std;

//constructor
OrderItem::OrderItem(int id,
	Customer* customer,
    Product* product,
    int qty,
	char* tm,
    int total){
        this->id = rand();
        this->customer = customer;
        this->product = product;
        this->qty = qty;
        time_t curr_time;
        curr_time = time(NULL);
        char *tm = ctime(&curr_time);
        this->tm = tm;
        this->total = total;
}

//getter methods
Customer* OrderItem::getCustomer(){
    return this->customer;
}
Product* OrderItem::getProduct(){
    return this->product;
}
int OrderItem::getQuantity(){
    return this->qty;
}
char* OrderItem::getTimeStamp(){
    return this->tm;
}
int OrderItem::getTotal(){
    return this->total;
}

//setter methods
void OrderItem::setQuantity(int qty){
    this->qty = qty;
}
void OrderItem::setProduct(Product* product){
    this->product = product;
}