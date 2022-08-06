#include "customerServiceDisplayManager.h"

int CustomerServiceDisplayManager::displayStartMenu(){
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

bool CustomerServiceDisplayManager::displayManageProductMenu(shared_ptr<ProductWrapper> product){
	cout<<"Found Product:";
	displayProduct(product);
	cout<<"Add product to cart?(Y/N)\n --> ";
	try{
		return getBoolChoice();
	}
	catch(...){
		cout<<"Please enter a valid option\n"<<linebreak;
		return displayManageProductMenu(product);
	}
}