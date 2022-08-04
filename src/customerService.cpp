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
			case 3:
				customerInterface();
			case 4:
				cartManager();
			default:
				if(getDM()->getExitConfirmation())return;
				break;
			}
		}
}

void CustomerService::customerInterface(){}
void CustomerService::cartManager(){}