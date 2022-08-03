#include <string>
using namespace std;
#include "customer.h"
#include "Product.h"

class OrderItem{
	private:
		int id;
		Customer* customer;
        Product* product;
        int qty;
		char* tm;
        int total;
	public:
		OrderItem(int id, Customer* customer, Product* product, int qty, char* tm, int total): id(id), Customer(customer), Product(product), qty(qty), tm(tm), total(total){};
};

