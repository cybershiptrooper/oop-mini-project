#include "customerWrapper.h"
#include <list>
#include "customerParser.h"

class CustomerManager
{
private:
	map<string, list<shared_ptr<CustomerWrapper>>> registeredCustomers; 
	CustomerManager(){};
	CustomerManager(const CustomerManager& s) = delete;
	CustomerManager& operator=(const CustomerManager& s) = delete;
		
public:
	static CustomerManager& getInstance(){
		static CustomerManager CM;
		return CM;
	}
	auto searchCustomer(char* phone);//exception for phone
	void deleteCustomer(){/*TODO*/};
	void addCustomer(){/*TODO*/};
	void write(){/*TODO*/};
	void read(){/*TODO*/};

};
