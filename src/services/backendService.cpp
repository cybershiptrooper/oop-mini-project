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
	syncProducts();
	return product;
}

shared_ptr<CustomerWrapper> BackendService::addCustomer(
	string name, string address, string phone){
	auto customer = make_shared<CustomerWrapper>(name, address, phone);
	CM.addCustomer(customer);
	syncCustomers();
	return customer;
}

void BackendService::updatePhone(shared_ptr<Customer> customer, string phone){
	for(auto i : CM.getCustomerList()){
		auto c1 = i->getCustomer();
		if(c1->getPhone() == phone) throw std::invalid_argument("Phone not unique");
	}
	customer->updatePhone(phone);
	syncCustomers();
}

shared_ptr<OrderItem> BackendService::createOrderItem(
	shared_ptr<Customer> customer,
	shared_ptr<ProductWrapper> product,
	int qty,
	time_t tm){
		assert(checkCanBuy(product, qty));
		//remove from inventory
		product->addToStock(-qty);
		//store in RAM
		int orderID = OM.createID(customer, product);
		
		auto order = make_shared<OrderItem>(
			orderID, 
			customer, product,
			qty, tm);
		// cerr<<"[backend]"<<tm << " " <<order->getTimeStamp()<<endl;
		OM.addOrderItem(order);
		//write to File
		syncOrders();
		return order;
}

list<shared_ptr<OrderItem>> BackendService::getAllOrdersOfProd(
	shared_ptr<ProductWrapper> product){
	list<shared_ptr<OrderItem>> ans;
	for(auto item : getAllOrders()){
		if( *(item->getProduct()) == *product){
			ans.push_back(item);
		}
	}
	return ans;
}