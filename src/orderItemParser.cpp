#include "orderItemParser.h"
#include "customerParser.h"
#include "customerManager.h"
#include "customer.h"
#include "productManager.h"

string OrderItemParser::parseToStr(shared_ptr<OrderItem> data){
	string ans = "";
    ans += data->getID();
    ans += ";";
	ans += data->getCustomer()->getName();
	ans += ";";
	ans += data->getCustomer()->getAddress();
	ans += ";";
	ans += data->getCustomer()->getPhone();
	ans += ";";
    ans += data->getProduct()->getName();
    ans += ";";
    ans += data->getProduct()->getCost();
    ans += ";";
    ans += data->getQuantity();
    ans += ";";
    ans += data->getTimeStamp();
    ans += ";";
    ans += data->getTotal();
	ans += ";\n";
	return ans;
}

shared_ptr<OrderItem> OrderItemParser::parseFromStr(string str, unsigned int orderID){
	stringstream ss(str);
	string custPhone, prodName, quantity, time, total;
	getline(ss, custPhone, ';');
    shared_ptr<CustomerWrapper> custWrap = CustomerManager::getInstance().searchCustomer(custPhone);
    auto customer = custWrap->getCustomer();
	getline(ss, prodName, ';');
    shared_ptr<ProductWrapper> prodWrap = ProductManager::getInstance().searchProduct(prodName);
    shared_ptr<Product> product = prodWrap->getProduct();
	getline(ss, quantity, ';');
    getline(ss, time, ';');
	getline(ss, total, ';'); 
	return make_shared<OrderItem>(orderID, customer, product, quantity, time, total);
}

//should be method of Parser class
/*string CustomerParser::getColumnAsStr(){
	string header;
	for(auto i : columns){
		header += i;
		header += ";";
	}
	return header;
}*/

void OrderItemParser::readFile(){
	list<string> data = file_manager.readFromBeginning();
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	int i = 1;
	for(auto item : data){
		auto orderItem = parseFromStr(item, i++);
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

