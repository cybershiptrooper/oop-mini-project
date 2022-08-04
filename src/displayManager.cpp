#include "displayManager.h"

int DisplayManager::getChoice(const unsigned int max_choices){
		int choice;
		try{
			cin >> choice;
			cout << linebreak;
			if(choice > max_choices or choice < 1){
				throw "No such option found";
			}
		}
		catch(...){
			cout<<"Please select a valid option\n";
			return -1;
		}
		return choice;
}

int DisplayManager::displayProductCategoryMenu(User user, bool create){
	if(create){
		try{
			if(user != Admin) throw "User not an admin";
		}
		catch(...){cout<<"You do not have the permission to dit product categories.";};
	}

	int max_choices = 0;//BackendService::getInstance();
	cout<<"Select a product category\n";
	for(int i = 0; i < max_choices; i++){
		cout<<i<<". "<<"<Product name>"<<"\n";
	}
	
	if(create){
		max_choices++;
		cout<<max_choices<<". Create a new category of product"<<"\n";
	}

	int choice = getChoice(max_choices);
	if(choice == -1) return displayProductCategoryMenu(user, create);
	return choice;
}