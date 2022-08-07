#include "cart.h"

double Cart::getTotal(){
		double total = 0;
		for(auto item : cartItems){
			double cost = (item.first)->getProduct()->getCost();
			total += cost*item.second;
		}
		double discount = customer->getMembership()->getDiscount();
		total *= 1-discount;
		total += non_discountable;
		return total;
}

double Cart::getDiscount(){
	double total = 0;
	for(auto item : cartItems){
		double cost = (item.first)->getProduct()->getCost();
		total += cost*item.second;
	}
	double discount = customer->getMembership()->getFees();
	return discount*total;
}

bool Cart::productInCart(shared_ptr<ProductWrapper> product){
	for(auto i : cartItems){
		if(*product == *(i.first)){
			return true;
		}
	}
	return false;
}

void Cart::addProduct(shared_ptr<ProductWrapper> product, int qty){
	if(productInCart(product)) throw invalid_argument("Product already in cart");
	if(BackendService::getInstance().checkCanBuy(product, qty)){
		cartItems[product] = qty;
	}
	else throw std::invalid_argument("Cannot buy product");
}

void Cart::removeProductFromCart(shared_ptr<ProductWrapper> product){
	for(auto it = cartItems.begin(); it != cartItems.end(); it++){
		if(*product == *((*it).first)){
			cartItems.erase(it);
			return;
		}
	}
}

void Cart::addMembershipToBill(MembershipCategory membership){
	// customer->setMembership(ToString(membership)); //Do this during checkout
	// non_discountable = customer->getMembership()->getFees();
	assert(customer != nullptr);
	assert(membership != No);
	if((membership) <= (customer->getMembership()->getType())) 
		throw std::invalid_argument("You already have purchased a better/same class in the past. ");
	if(boughtMembership > No){removeMembershipFromBill();}
	boughtMembership = membership;
	string pname = ToString(boughtMembership);
	pname+= " Membership";
	membershipProd = make_shared<ProductWrapper>(pname, 0, "Membership", 1);
	cartItems[membershipProd] = 1;
}

double Cart::checkout(){
	if(!checkOutValid()) throw std::invalid_argument("Invalid Checkout");
	if((boughtMembership) > (customer->getMembership()->getType())){
		customer->setMembership(ToString(boughtMembership));
		non_discountable = customer->getMembership()->getFees();
	}
	for(auto i : cartItems){
		i.first->addToStock(-i.second);
		assert(i.first->getStock() >= 0);
		//create order item
		/*TODO*/
	}
	return getTotal();

}