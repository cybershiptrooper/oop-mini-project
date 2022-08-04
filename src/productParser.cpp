#include "productParser.h"

string ProductParser::parseToStr(shared_ptr<ProductWrapper> data){
	string ans = "";
	ans += (data->getProduct()->getName());
	ans += ";";
	ans += (data->getProduct()->getCost());
	ans += ";";
	ans += (data->getCategory());
	ans += ";";
	ans += data->getStock();
	ans += ";\n";
	return ans;
}

shared_ptr<ProductWrapper> ProductParser::parseFromStr(string str){
	stringstream ss(str);
	string name, cost, category, stock;
	getline(ss, name, ';'); //Exception!!
	getline(ss, cost, ';'); 
	getline(ss, category, ';');
	getline(ss, stock, ';'); 
	return make_shared<ProductWrapper>(name, stoi(cost), category, stoi(stock));
}
string ProductParser::getColumnAsStr(){
	string header;
	for(auto i : columns){
		header += i;
		header += ";";
	}
	return header;
}
void ProductParser::readFile(){
	list<string> data = file_manager.readFromBeginning();
	
	assert(getColumnAsStr() == data.front());
	data.pop_front();
	int i = 1;
	for(auto item : data){
		auto Product = parseFromStr(item);
		ProductManager::getInstance().addProduct(Product);
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