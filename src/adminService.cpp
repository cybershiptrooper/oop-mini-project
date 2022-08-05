#include "adminService.h"

void AdminService::start(){
		while(true){
			int choice = getDM()->displayStartMenu();
			switch (choice)
			{
			case 1:
				searchProduct();break;
			case 2:
				displayProducts();break;
			case 3:
				addNewProduct();break;
			default:
				return;
			}
		}
}

void AdminService::addNewProduct(){
	int choice = getDM()->displayProductCategoryMenu(user, true);
	int max_choices = BackendService::getInstance().getProductSize();
	string category;
	if(choice > max_choices){
		category = getDM()->getName("category");
		BackendService::getInstance().createCategory(category);
		getDM()->createConfirm("category");
	}
	else{
		category = BackendService::getInstance().getCategory(choice);
	}
	
	string product = getDM()->getName("product");
	int inventory;
	
	while(true){
		try{
			std::string a = "quantity of product";
			std::string b = "Please enter the ";
			inventory = stoi(getDM()->getName(a,b));
			if(inventory < 0) throw "incorrect qty";
			break;
		}
		catch(...){
			"Please enter a non-negative quantity";
		}
	}
	double cost;
	while(true){
		try{
			std::string a = "cost of product";
			std::string b = "Please enter the ";
			cost = stoi(getDM()->getName(a,b));
			if(cost < 0) throw "incorrect cost";
			break;
		}
		catch(...){
			"Please enter a non-negative quantity";
		}
	}

	BackendService::getInstance().addProduct(product, cost, category, inventory);
	getDM()->createConfirm("product");
}