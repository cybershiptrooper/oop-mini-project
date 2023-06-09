#pragma once
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "orderItem.h"
#include "orderItemManager.h"
#include "iowriter.h"
using namespace std;


class OrderItemParser
{
private:
	const vector<string> columns = {"custPhone", "pName", "pCategory", "quantity", "time"};
	IOWriter file_manager;
	OrderItemParser(): file_manager(IOWriter("data/orderItem.data")){};
	OrderItemParser(const OrderItemParser& s) = delete;
	OrderItemParser& operator=(const OrderItemParser& s) = delete;

	string parseToStr(shared_ptr<OrderItem> data);
	shared_ptr<OrderItem> parseFromStr(string str);
	string getColumnAsStr();
public:
	static OrderItemParser& getInstance(){
		static OrderItemParser OP;
		return OP;
	}
	void readFile();
	void writeFile();
};

//TODO - destructor, deleteInstance()
//cols - custPhone, prodName, 