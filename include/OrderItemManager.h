#include "OrderItemWrapper.h"
#include <list>
#include "OrderItemParser.h"

class OrderItemManager
{
private:
	map<string, list<shared_ptr<OrderItem*>>> orderedItems; 
	OrderItemManager(){};
	//OrderItemManager(const OrderItemManager& s) = delete;
	//OrderItemManager& operator=(const OrderItemManager& s) = delete;
		
public:
	static OrderItemManager& getInstance(){
		static OrderItemManager OM;
		return OM;
	}
    static OrderItemManager& deleteInstance(){}
	void placeOrder(){/*TODO*/};
};
