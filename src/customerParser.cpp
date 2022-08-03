#include "customerParser.h"

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

shared_ptr<CustomerWrapper> CustomerParser::parseFromStr(string str, unsigned int serialID){
	stringstream ss(str);
	string name, address, phone, membership;
	getline(ss, name, ';'); //Exception!!
	getline(ss, address, ';'); 
	getline(ss, phone, ';');
	getline(ss, membership, ';'); 
	return make_shared<CustomerWrapper>(serialID, name, address, phone, membership);
}
string CustomerParser::getColumnAsStr(){
	string header;
	for(auto i : columns){
		header += i;
		header += ";";
	}
	return header;
}
void CustomerParser::readFile(){
	list<string> data = file_manager.readFromBeginning();
	
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	int i = 1;
	for(auto item : data){
		auto customer = parseFromStr(item, i++);
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