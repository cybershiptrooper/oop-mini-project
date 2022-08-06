#include "customerParser.h"
#include <iostream>
string CustomerParser::parseToStr(shared_ptr<CustomerWrapper> data){
	string ans = "";
	ans += (data->getCustomer()->getName());
	ans += ";";
	ans += (data->getCustomer()->getAddress());
	ans += ";";
	ans += (data->getCustomer()->getPhone());
	ans += ";";
	ans += data->getMembership()->getType();
	ans += ";\n";
	return ans;
}

shared_ptr<CustomerWrapper> CustomerParser::parseFromStr(string str
// , unsigned int serialID
){
	stringstream ss(str);
	string name, address, phone, membership;
	getline(ss, name, ';'); //Exception!!
	getline(ss, address, ';'); 
	getline(ss, phone, ';');
	getline(ss, membership, ';'); 
	// return make_shared<CustomerWrapper>(serialID, name, address, phone, membership);
	return make_shared<CustomerWrapper>(name, address, phone, membership);
}
string CustomerParser::getColumnAsStr(){
	string header;
	for(int i = 0; i < columns.size(); i++){
		header += columns[i];
		if(i < columns.size()-1)header += "; ";
		else header += ";";
	}
	return header;
}
void CustomerParser::readFile(){
	list<string> data = file_manager.readFromBeginning();
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	if(data.empty())return;
	string utr = data.front();
	while(not data.empty()){
		string str = data.front();
		// assert(str == utr);
		data.pop_front();
		auto customer = parseFromStr(str);
		CustomerManager::getInstance().addCustomer(customer);
	}
}

void CustomerParser::writeFile(){
	list<string> data;
	data.push_back(getColumnAsStr());
	for(auto item : CustomerManager::getInstance().getCustomerList()){
		data.push_back(parseToStr(item));
	}
	file_manager.writeFromBeginning(data);
}