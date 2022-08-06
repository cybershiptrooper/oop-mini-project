#include "adminService.h"

void AdminService::start(){
		while(true){
			int choice = getDM()->displayStartMenu();
			switch (choice)
			{
			case 1:
				try{
					auto product = searchProduct();
					manageProduct(product);
				}
				catch(...){}
				break;
			case 2:
				displayProducts();break;
			case 3:
				addNewProduct();break;
			// case 4:
				// getDM()->displayAllOrderItems();
			default:
				return;
			}
			getDM()->BR();
			BackendService::getInstance().syncFiles();
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
	try {
		auto ans = BackendService::getInstance().searchProduct(product, category);
		getDM()->dispAlreadyExists(ans);
		manageProduct(ans);
	}
	catch(const std::invalid_argument& e){
		cout<<"A new product will be created.\n";
	}

	int inventory = getDM()->getNumber("quantity of product");
	double cost = getDM()->getFloatingNumber("cost of the product");
	auto pw = BackendService::getInstance().addProduct(product, cost, category, inventory);
	getDM()->createConfirm("product");
	getDM()->displayProduct(pw);
}

void AdminService::manageProduct(shared_ptr<ProductWrapper> product){
		while(true){
			int choice = getDM()->displayManageProductMenu(product);
			switch (choice)
			{
			case 1:
				viewInventoryStats(product);
				break;
			case 2:
				{int additionalStock = getDM()->getNumber("quantity you want to add to stock");
				product->addToStock(additionalStock);
				break;}
			case 3:
				BackendService::getInstance().deleteProduct(product);
				getDM()->deleteConfirm("Product");
				return;
				break;
			default:
				return;
			}
			getDM()->BR();
			BackendService::getInstance().syncFiles();
		}
}

void AdminService::viewInventoryStats(shared_ptr<ProductWrapper> product){
	//get all past orders including this product 

	//get daily total 

	//other stats 
}