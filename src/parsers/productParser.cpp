#include "productParser.h"
#include <string>
#include <iostream>
string ProductParser::parseToStr(shared_ptr<ProductWrapper> data){
	string ans = "";
	ans += (data->getProduct()->getName());
	ans += ";";
	ans += to_string(data->getProduct()->getCost());
	ans += ";";
	ans += (data->getCategory());
	ans += ";";
	ans += to_string(data->getStock());
	ans += ";";
	return ans;
}

shared_ptr<ProductWrapper> ProductParser::parseFromStr(string str){
	istringstream ss(str);
	string name, coststr, category, stock;
	getline(ss, name, ';'); //Exception!!
	getline(ss, coststr, ';'); 
	getline(ss, category, ';');
	getline(ss, stock, ';'); 
	
	int stocknumeric = stoi(stock);
	double costnumeric = stod(coststr);
	auto ans = make_shared<ProductWrapper>(name, costnumeric, category, stocknumeric);
	return ans;
}

string ProductParser::getColumnAsStr(){
	string header;
	for(int i = 0; i < columns.size(); i++){
		header += columns[i];
		if(i < columns.size()-1)header += "; ";
		else header += ";";
	}
	return header;
}

void ProductParser::readFile(){
	list<string> data = file_manager.readFromBeginning();
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	if(data.empty())return;
	string utr = data.front();
	while(not data.empty()){
		string str = data.front();
		// assert(str == utr);
		data.pop_front();
		auto product = parseFromStr(str);
		//cerr<<"original"<<&(*product)<<endl;
		ProductManager::getInstance().addProduct(product);
	}
}

void ProductParser::writeFile(){
	list<string> data;
	data.push_back(getColumnAsStr());
	for(auto cat : ProductManager::getInstance().getCatalouge()){
		for(auto item : cat.second){
			data.push_back(parseToStr(item));
		}
	}
	file_manager.writeFromBeginning(data);
}