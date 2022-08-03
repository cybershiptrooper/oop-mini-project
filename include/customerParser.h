#pragma once
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <assert.h>
#include "customerWrapper.h"
#include "customerManager.h"
#include "iowriter.h"
using namespace std;

class CustomerParser
{
private:
	const vector<string> columns = {"Name", "Address", "Phone", "Membership"};
	IOWriter file_manager;
	CustomerParser(): file_manager(IOWriter("data/customer.data")){};
	CustomerParser(const CustomerParser& s) = delete;
	CustomerParser& operator=(const CustomerParser& s) = delete;

	string parseToStr(shared_ptr<CustomerWrapper> data);
	shared_ptr<CustomerWrapper> parseFromStr(string str, unsigned int serialID);
	string getColumnAsStr();
public:
	static CustomerParser& getInstance(){
		static CustomerParser CP;
		return CP;
	}
	void readFile();
	void writeFile();
};

//Exception for Parse from str
