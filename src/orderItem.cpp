#include <string>
#include <iostream>
#include <ctime>
#include "customer.h"
#include "orderItem.h"

using namespace std;

//getter methods
int OrderItem::getID(){
    return id;
}
shared_ptr<Customer> OrderItem::getCustomer(){
    return this->customer;
}
shared_ptr<Product> OrderItem::getProduct(){
    return this->product;
}
int OrderItem::getQuantity(){
    return this->qty;
}
char* OrderItem::getTimeStamp(){
    return this->tm;
}
double OrderItem::getTotal(){
    return product->getCost()*qty;
}

//setter methods
void OrderItem::setQuantity(int qty){
    this->qty = qty;
}
void OrderItem::setProduct(shared_ptr<Product> product){
    this->product = product;
}