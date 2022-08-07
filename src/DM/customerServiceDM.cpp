#include "customerServiceDisplayManager.h"

int CustomerServiceDisplayManager::displayStartMenu(){
		BR();
		int max_choices = 0;
		cout<<"Please select an option to proceed: \n";
		max_choices++;cout<<max_choices<<". Search for a Product\n";
		max_choices++;cout<<max_choices<<". Display products\n";
		max_choices++;cout<<max_choices<<". Access customer interface\n";
		max_choices++;cout<<max_choices<<". Manage Cart\n";
		max_choices++;cout<<max_choices<<". Exit\n";
		cout<<" --> ";
		int choice = getChoice(max_choices);
		if(choice == -1) return displayStartMenu();
		return choice;
}

int CustomerServiceDisplayManager::displayManageProductInCartMenu(shared_ptr<ProductWrapper> product){
	BR();
	cout<<"Product exists in Cart.\nPlease select what you want to do with the product:\n";
	int max_choices = 0;
	max_choices++;cout<<max_choices<<". Remove from cart\n";
	max_choices++;cout<<max_choices<<". Edit quantity of items\n";
	max_choices++;cout<<max_choices<<". Do nothing\n";
	cout<<" --> ";
	int choice = getChoice(max_choices);
	if(choice == -1) return displayManageProductInCartMenu(product);
	return choice;	
}

bool CustomerServiceDisplayManager::addToCart(){
	cout<<"Add product to cart?(Y/N)\n --> ";
	try{
		return getBoolChoice();
	}
	catch(...){return addToCart();}
}

int CustomerServiceDisplayManager::displayCartManageMenu(){
	BR();
	cout<<"Please select an option to proceed:\n";
	int max_choices = 0;
	max_choices++;cout<<max_choices<<". Display cart\n";
	max_choices++;cout<<max_choices<<". Remove item from cart\n";
	max_choices++;cout<<max_choices<<". Manage product in cart\n";
	max_choices++;cout<<max_choices<<". Add/Edit customer Details\n";
	max_choices++;cout<<max_choices<<". Remove purchased membership from bill\n";
	max_choices++;cout<<max_choices<<". Proceed to checkout\n";
	max_choices++;cout<<max_choices<<". Discard your purchases\n";

	max_choices++;cout<<max_choices<<". Return to main menu\n";
	cout<<" --> ";
	int choice = getChoice(max_choices);
	if(choice == -1) return displayCartManageMenu();
	return choice;	
}

int CustomerServiceDisplayManager::displayCustomerMenu(){
	BR();
	cout<<"Please select an option to proceed:\n";
	int max_choices = 0;
	max_choices++;cout<<max_choices<<". Change membership\n";
	max_choices++;cout<<max_choices<<". Discard Cart\n";
	max_choices++;cout<<max_choices<<". Display customer details\n";
	max_choices++;cout<<max_choices<<". Edit customer details\n";
	max_choices++;cout<<max_choices<<". Exit\n";
	cout<<" --> ";
	int choice = getChoice(max_choices);
	if(choice == -1) return displayCartManageMenu();
	return choice;	
}

void CustomerServiceDisplayManager::displayCartItems(
	const map<shared_ptr<ProductWrapper>, unsigned int>& items){
	BR();
	if(items.empty()){cout<<"Nothing in cart yet!\n";return;}
	int i = 1;
	for(auto item : items){
		cout<<i++<<". "<<item.first->getProduct()->getName()<<endl;
		cout<<"Category "<<item.first->getCategory()<<endl;
		cout<<"Qty: "<<item.second<<endl<<endl;
	}
}

void CustomerServiceDisplayManager::confirmCheckout(
	double total,
	const map<shared_ptr<ProductWrapper>, unsigned int>& items
	){
	cout<<"Confirmed Order. The following items were purchased:\n";
	displayCartItems(items);
	BR();
	cout<<"The total bill is "<<total<<endl;
}

void assertcheck(string phone){
	for(int i = 0; i < phone.length(); i++){
		if(phone[i] < '0' or phone[i] > '9' )
			throw std::invalid_argument("Bad letter");
	}
	if(phone.length()!=10)throw std::invalid_argument("Bad length");
	if(phone[0] < '7')throw std::invalid_argument("Bad number");
	// cout<<"--> "<<stol(phone)<<endl;
}

string CustomerServiceDisplayManager::getPhone(){
	string phone;
	cout<<"Enter phone number:\n --> ";
	cin >> phone;
	while(true){	
		try{
			assertcheck(phone);
			return phone;
		}
		catch(const std::exception& e)
		{
			clearCIN();
			std::cerr << "Please Enter a valid phone number\n -->";
		}
	}
}

int CustomerServiceDisplayManager::displayMembershipMenu(){
	BR();
	cout<<"Please select what type of membership you want to purchase:\n";
	cout<<"1. Classic Membership (cost: "
		<<ClassicMembership().getFees()
		<<", discount: "<<ClassicMembership().getDiscount()<<")\n";
	cout<<"2. Gold Membership (cost: "
		<<ClassicMembership().getFees()
		<<", discount: "<<ClassicMembership().getDiscount()<<")\n";
	cout<<"3. Platinum Membership (cost: "
		<<ClassicMembership().getFees()
		<<", discount: "<<ClassicMembership().getDiscount()<<")\n";
	cout<<"4. Remove membership purchase\n -->";
	int choice = getChoice(4);
	if(choice == -1) return displayMembershipMenu();
	if(choice == 4) return 0;
	return (choice);
}

int CustomerServiceDisplayManager::displayEditCustCategoryMenu(){
	BR();
	cout<<"Please select an option to proceed:\n";
	int max_choices = 0;
	max_choices++;cout<<max_choices<<". Edit Address\n";
	max_choices++;cout<<max_choices<<". Edit Phone number\n";
	max_choices++;cout<<max_choices<<". Return\n";
	cout<<" --> ";
	int choice = getChoice(max_choices);
	if(choice == -1) return displayCartManageMenu();
	return choice;	
}