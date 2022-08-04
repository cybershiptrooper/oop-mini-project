#pragma once
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <assert.h>
#include "productWrapper.h"
#include "productManager.h"
#include "iowriter.h"
using namespace std;

class ProductParser
{
private:
	const vector<string> columns = {"Name", "Cost", "Category", "Stock"};
	IOWriter file_manager;
	ProductParser(): file_manager(IOWriter("data/Product.data")){};
	ProductParser(const ProductParser& s) = delete;
	ProductParser& operator=(const ProductParser& s) = delete;

	string parseToStr(shared_ptr<ProductWrapper> data);
	shared_ptr<ProductWrapper> parseFromStr(string str);
	string getColumnAsStr();
public:
	static ProductParser& getInstance(){
		static ProductParser PP;
		return PP;
	}
	void readFile();
	void writeFile();
};

//Exception for Parse from str
