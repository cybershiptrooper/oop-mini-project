#include "orderItemParser.h"
#include "customerParser.h"
#include "customerManager.h"
#include "customer.h"
#include "productManager.h"
#include "iowriter.h"
// #include <iostream>
string OrderItemParser::parseToStr(shared_ptr<OrderItem> data){
	string ans = "";
    ans += to_string(data->getID());
	ans += ";";
	ans += data->getCustomer()->getPhone();
	ans += ";";
    ans += data->getProduct()->getName();
    ans += ";";
    ans += to_string(data->getQuantity());
    ans += ";";
    ans += string(data->getTimeStamp());
	ans += ";\n";
	return ans;
}

shared_ptr<OrderItem> OrderItemParser::parseFromStr(string str){
	stringstream ss(str);
	string custPhone, prodName, quantity, time;
	getline(ss, custPhone, ';');
    shared_ptr<CustomerWrapper> custWrap = CustomerManager::getInstance().searchCustomer(custPhone);
    shared_ptr<Customer> customer = custWrap->getCustomer();
	getline(ss, prodName, ';');
    shared_ptr<ProductWrapper> prodWrap = ProductManager::getInstance().searchProduct(prodName);
    shared_ptr<Product> product = prodWrap->getProduct();
	getline(ss, quantity, ';');
	int qty = stoi(quantity);
	// int total1 = stoi(total);
    getline(ss, time, ';');
	// getline(ss, total, ';'); 
	char* tm = const_cast<char*>(time.c_str());
	int orderID = OrderItemManager::getInstance().createID(customer, product);
	return make_shared<OrderItem>(orderID, customer, product, qty, tm);
}

//should be method of Parser class
string OrderItemParser::getColumnAsStr(){
	string header;
	for(int i = 0; i < columns.size(); i++){
		header += columns[i];
		if(i < columns.size()-1)header += "; ";
		else header += ";";
	}
	return header;
}

void OrderItemParser::readFile(){
	// list<string> data = file_manager.readFromBeginning();
	// // assert(getColumnAsStr() == data.front());
	// data.pop_front();
	// // data.pop_back();
	// // cout<<data.back();
	// if(data.empty())return;
	// for(auto item : data){
	// 	auto orderItem = parseFromStr(item);
	// 	OrderItemManager::getInstance().addOrderItem(orderItem);
	// }
	list<string> data = file_manager.readFromBeginning();
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	if(data.empty())return;
	string utr = data.front();
	while(not data.empty()){
		string str = data.front();
		// assert(str == utr);
		data.pop_front();
		auto orderItem = parseFromStr(str);
		OrderItemManager::getInstance().addOrderItem(orderItem);
	}
}

void OrderItemParser::writeFile(){
	list<string> data;
	data.push_back(getColumnAsStr());
	for(auto item : OrderItemManager::getInstance().getListOfOrderedItems()){
		data.push_back(parseToStr(item));
	}
	file_manager.writeFromBeginning(data);
}

