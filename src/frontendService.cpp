#include "frontendService.h"

void FrontendService::searchProduct(){
	int choice = getDM()->displayProductCategoryMenu(user);
	
	//Backend.getInstance().getPoductManager().searchProduct();
}