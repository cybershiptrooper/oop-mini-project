#include "customerService.h"

void CustomerService::start(){
		while(true){
			main_flag = false;
			int choice = getDM()->displayStartMenu();
			switch (choice)
			{
			case 1:
				try{
					auto product = searchProduct();
					manageProduct(product);
				}catch(...){}
				break;
			case 2:
				displayProducts();
				break;
			case 3:
				customerInterface();
				break;
			case 4:
				manageCart();
				break;
			default:
				if(getDM()->getExitConfirmation())return;
				break;
			}
			BackendService::getInstance().syncFiles();
		}
}

void CustomerService::manageProduct(shared_ptr<ProductWrapper> product){
	if(cart->productInCart(product)){
		int choice = getDM()->displayManageProductInCartMenu(product);
		switch (choice)
		{
		case 1://Remove from cart
			cart->removeProductFromCart(product);
			getDM()->deleteConfirm("Product");
			break;
		case 2://update qty
			updateCartQty(product);
			break;
		default://Do nothing
			return;
		}
	}
	else{
		if(getDM()->addToCart()){
			int qty = getDM()->getNumber("quantity");
			cart->addProduct(product, qty);
			cout<<"Added to cart!\n";
		}
	}
}

void CustomerService::updateCartQty(shared_ptr<ProductWrapper> product){
	int newQty = getDM()->getNumber("quantity");
	if(BackendService::getInstance().checkCanBuy(product, newQty)){
		cart->removeProductFromCart(product);
		cart->addProduct(product, newQty);
	}
	else{
		getDM()->displayNotInStock();
	}
}

void CustomerService::customerInterface(){/*TODO*/
	if(cart->customerExists()){
		while(true){
		int choice = getDM()->displayCustomerMenu();
		switch (choice)
		{
		case 1://add membership
		try
		{
			int membership = getDM()->displayMembershipMenu();
			//add to bill
			cart->addMembershipToBill(static_cast<MembershipCategory>(membership));
			cout<<"Membership added to cart\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
		case 2://discard cart
			resetCart();
			getDM()->deleteConfirm("Cart");
			main_flag = true;
			return;
		case 3://display details
			getDM()->displayCustomer(cart->getCustomer());
			break;
		case 4://edit details
			editMemberDetail();
			break;
		default://return
			return;
		}
		BackendService::getInstance().syncFiles();
		}
	}
	else{
		//enter phone number
		string phone = getDM()->getPhone();
		//check phone number in DB
		auto customer = BackendService::getInstance().searchCustomer(phone);
		if(customer != nullptr){
			//add existing
			cart->addCustomer(customer);
		}
		else{
			//add new
			string name = getDM()->getName(
			"Please enter customer name",
			"Adding a new customer\n");
			string address = getDM()->getName("Please enter address","");
			auto customer = BackendService::getInstance().addCustomer(name, address, phone);
			cout<<"Customer added\n";
			getDM()->displayCustomer(customer);
			cart->addCustomer(customer);
		}
	}
	BackendService::getInstance().syncFiles();

	customerInterface();
}

void CustomerService::manageCart(){
	while(true){
		int choice = getDM()->displayCartManageMenu();
		switch(choice)
		{
		case 1://display cart 
			{
				const auto items = cart->getCartItems();
				getDM()->displayCartItems(items);
			}
			break;
		case 2://remove item from cart
			{
				try{
				//search
				auto product = searchProductInCart();
				//remove
				cart->removeProductFromCart(product);
				getDM()->deleteConfirm("Product");
				}catch(...){
					getDM()->dispNotInCart();
				}
			}
			break;
		case 3://manage product
			{
				try{
					auto product = searchProductInCart();
					manageProduct(product);
				}catch(...){getDM()->dispNotInCart();}
			}
			break;
		case 4://customer interface
			customerInterface();
			if(main_flag)return;
			break;
		case 5://checkout
			try{
				double total=cart->checkout();
				getDM()->confirmCheckout(total, cart->getCartItems());
				resetCart();
				return;
			}
			catch(const std::exception& e){
				cout<<"Cart is not complete to checkout yet"<<endl;
			}
			break;
		case 6://discard cart
			resetCart();
			getDM()->deleteConfirm("Cart");
			return;
		case 7://remove membership purchase
			cart->removeMembershipFromBill();
		default://return
			return;
		}
	}
}

shared_ptr<ProductWrapper> CustomerService::searchProductInCart(){
	int choice = getDM()->displayProductCategoryMenu(user);
	string category = BackendService::getInstance().getCategory(choice);
	shared_ptr<ProductWrapper> product;
	string pname = getDM()->getName("product");
	for(auto i : cart->getCartItems()){
		if(
			((i.first)->getProduct()->getName() == pname)
			and ((i.first)->getCategory() == category)
		){
			return i.first;
		}
	}
	throw std::invalid_argument("[customer services] No such product");
}

void CustomerService::editMemberDetail(){
	int choice = getDM()->displayEditCustCategoryMenu();
	assert(cart->customerExists());
	switch (choice)
	{
	case 1://edit address
		{
			string address = getDM()->getName("Please enter address","");
			cart->getCustomer()->getCustomer()->updateAddress(address);
			cout<<"address changed to "<<address<<endl;
		}
		break;
	case 2://edit phone
		{
			try
			{
				string phone = getDM()->getPhone();
				BackendService::getInstance().updatePhone(
					cart->getCustomer()->getCustomer(), phone);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
		break;
	default://return
		return;
	}
	BackendService::getInstance().syncFiles();
	editMemberDetail();
}