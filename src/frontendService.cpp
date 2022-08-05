#include "frontendService.h"
#include <string>

void FrontendService::searchProduct(){
	int choice = getDM()->displayProductCategoryMenu(user);
	shared_ptr<ProductWrapper> product;
	if(choice < 0) return;
	string pname = getDM()->getName("product");
	try{	
		if(choice > BackendService::getInstance().getProductSize())
			product = BackendService::getInstance().searchProduct(pname);
		else	
			product = BackendService::getInstance().searchProduct(pname, choice);
	}
	catch(...){
		getDM()->productNotFound();return;
	}	
	// if(product == nullptr){ }
	bool choice2 = getDM()->displayManageProductMenu(product);

}

void FrontendService::displayProducts(){
	int choice = getDM()->displayProductCategoryMenu(user);
	shared_ptr<ProductWrapper> product;
	if(choice < 0) return;
	if(choice > BackendService::getInstance().getProductSize()){
		getDM()->displayProducts();
		return;
	}
	getDM()->displayProducts(BackendService::getInstance().getCategory(choice));
}