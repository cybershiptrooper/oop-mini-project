#pragma once
#include "displayManager.h"

class CustomerServiceDisplayManager: public DisplayManager
{
private:
public:
	int displayStartMenu();
	bool getExitConfirmation(){return true;};
	bool displayManageProductMenu(shared_ptr<ProductWrapper> product);
	int displayManageProductInCartMenu(shared_ptr<ProductWrapper> product);
	int displayCartManageMenu();
	int displayCustomerMenu();
	bool addToCart();

	void displayCartItems(const map<shared_ptr<ProductWrapper>, unsigned int>& items);
	void displayNotInStock(){cout<<"Sorry, we don't have these many products in stock.\n";}
	void confirmCheckout(
		double total, 
		const map<shared_ptr<ProductWrapper>, unsigned int>& items);
	string getPhone();
	int displayMembershipMenu();
	int displayEditCustCategoryMenu();
	void dispNotInCart(){cout<<"No such product in cart!\n";}
};

