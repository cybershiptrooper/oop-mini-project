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
    ans += data->getProduct()->getProduct()->getName();
    ans += ";";
    ans += to_string(data->getQuantity());
    ans += ";";
    ans += string(data->getTimeStamp());
	ans += ";";
	return ans;
}

shared_ptr<OrderItem> OrderItemParser::parseFromStr(string str){
	stringstream ss(str);
	string custPhone, pName, pCategory, quantity, time;
	getline(ss, custPhone, ';');
    shared_ptr<CustomerWrapper> custWrap = CustomerManager::getInstance().searchCustomer(custPhone);
    shared_ptr<Customer> customer = custWrap->getCustomer();
	getline(ss, pName, ';');
	getline(ss, pCategory, ';');
    shared_ptr<ProductWrapper> product = ProductManager::getInstance().searchProduct(
		pName, pCategory);
	getline(ss, quantity, ';');
	int qty = stoi(quantity);
    getline(ss, time, ';');
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
	list<string> data = file_manager.readFromBeginning();
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	while(not data.empty()){
		string str = data.front();
		data.pop_front();
		try
		{
			auto orderItem = parseFromStr(str);
			OrderItemManager::getInstance().addOrderItem(orderItem);
		}
		catch(const std::exception& e)
		{
			cerr<<"Could not read product: "<<e.what()<<endl;
			continue;
		}
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

