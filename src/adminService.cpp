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

}