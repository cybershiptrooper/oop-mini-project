#include "frontendService.h"
#include <string>

shared_ptr<ProductWrapper> FrontendService::searchProduct(){
	int choice = getDM()->displayProductCategoryMenu(user);
	shared_ptr<ProductWrapper> product;
	
	string pname = getDM()->getName("product");
	try{	
		if(choice > BackendService::getInstance().getProductSize())
			product = BackendService::getInstance().searchProduct(pname);
		else
			product = BackendService::getInstance().searchProduct(pname, choice);
	}
	catch(...){
		getDM()->productNotFound();
		throw;
	}	
	// if(product == nullptr){ }
	// bool choice2 = getDM()->displayManageProductMenu(product);
	getDM()->productFound(product);
	return product;
}

void FrontendService::displayProducts(){
	int choice = getDM()->displayProductCategoryMenu(user);
	// shared_ptr<ProductWrapper> product;
	// if(choice < 0) return;
	int max_choices = BackendService::getInstance().getProductSize();
	getDM()->BR();
	if(choice > max_choices){
		getDM()->displayProducts();
		return;
	}
	string category = BackendService::getInstance().getCategory(choice);
	// cout<<category<<endl;
	getDM()->displayProducts(category);
}