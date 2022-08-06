#include "cart.h"

double Cart::getTotal(){
		double total = 0;
		for(auto item : cartItems){
			double cost = (item.first)->getProduct()->getCost();
			total += cost*item.second;
		}
		double discount = customer->getMembership()->getFees();
		total *= 1-discount;
		total += non_discountable;
		return total;
};

void Cart::addProduct(shared_ptr<ProductWrapper> product, int qty){
		if(BackendService::getInstance().checkCanBuy(product, qty)){
			cartItems[product] = qty;
		}
		else throw std::invalid_argument("Cannot buy product");
};

void Cart::addMembershipToBill(MembershipCategory membership){
	customer->setMembership(ToString(membership));
	non_discountable = customer->getMembership()->getFees();
}