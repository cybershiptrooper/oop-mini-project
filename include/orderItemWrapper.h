#include "orderItem.h"

class OrderItemWrapper{
	private:
		OrderItem* item;
        int qty_left;
		
	public:
		OrderItemWrapper(OrderItem* item, int qty_left);
		int getQtyLeft(){return qty_left};
};
