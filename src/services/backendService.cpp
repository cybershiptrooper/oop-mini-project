#include "backendService.h"

string BackendService::getCategory(int choice){
	auto& catalogue = PM.getCatalouge(); 
	auto it = catalogue.begin();
	for(int i = 0; i <choice-1; i++){
		it++;
	}
	return (*it).first;
}

shared_ptr<ProductWrapper> BackendService::addProduct(
	string name, double cost, string category, int stock){
	//store in RAM
	auto product = make_shared<ProductWrapper>(name, cost, category, stock);
	PM.addProduct(product);
	//write to File
	ProductParser::getInstance().writeFile();
	return product;
}

shared_ptr<OrderItem> BackendService::createOrderItem(
	shared_ptr<Customer> customer,
	shared_ptr<ProductWrapper> product,
	int qty,
	char* tm){
		assert(checkCanBuy(product, qty));
		//remove from inventory
		product->addToStock(-qty);
		//store in RAM
		int orderID = OM.createID(customer, product->getProduct());
		auto order = make_shared<OrderItem>(
			orderID, 
			customer, product->getProduct(),
			qty, tm);
		//write to File
		OrderItemParser::getInstance().writeFile();
		return order;
}
