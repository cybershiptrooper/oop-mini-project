#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "OrderItem.h"
#include "OrderItemManager.h"
#include "iowriter.h"
using namespace std;


class OrderItemParser
{
private:
	const vector<string> columns = {"custPhone", "prodName", "quantity", "time", "total"};
	IOWriter file_manager;
	OrderItemParser(): file_manager(IOWriter("data/orderItem.data")){};
	OrderItemParser(const OrderItemParser& s) = delete;
	OrderItemParser& operator=(const OrderItemParser& s) = delete;

	string parseToStr(shared_ptr<OrderItem> data);
	shared_ptr<OrderItem> parseFromStr(string str, unsigned int orderID);
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