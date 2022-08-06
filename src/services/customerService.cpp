#include "customerService.h"

void CustomerService::start(){
		while(true){
			int choice = getDM()->displayStartMenu();
			switch (choice)
			{
			case 1:
				searchProduct();
				break;
			case 2:
				displayProducts();
				break;
			case 3:
				customerInterface();
				break;
			case 4:
				cartManager();
				break;
			default:
				if(getDM()->getExitConfirmation())return;
				break;
			}
		}
}

void CustomerService::customerInterface(){
	
}
void CustomerService::cartManager(){}