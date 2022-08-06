#include "adminServiceDisplayManager.h"

int AdminServiceDisplayManager::displayStartMenu(){
		int max_choices = 0;
		cout<<"Please select an option to proceed: \n";
		max_choices++;cout<<max_choices<<". Search for a Product\n";
		max_choices++;cout<<max_choices<<". View inventory stats\n";
		max_choices++;cout<<max_choices<<". Add a new Product\n";
		// max_choices++;cout<<max_choices<<". [test] Display all order items\n";
		// max_choices++;cout<<max_choices<<". \n";
		max_choices++;cout<<max_choices<<". Exit\n";
		cout<<" --> ";
		int choice = getChoice(max_choices);
		if(choice == -1) return displayStartMenu();
		return choice;
}


int AdminServiceDisplayManager::displayManageProductMenu(shared_ptr<ProductWrapper> product){
		int choice = -1;
		while(choice < 1){
			int max_choices = 0;
			cout<<linebreak;
			cout<<"Please select what you want to do with the product: \n";
			max_choices++;cout<<max_choices<<". View inventory stats\n";
			max_choices++;cout<<max_choices<<". Add more items to inventory\n";
			max_choices++;cout<<max_choices<<". Delete product\n";
			max_choices++;cout<<max_choices<<". Do nothing\n";
			cout<<" --> ";
			choice = getChoice(max_choices);
		}
		return choice;
}

// void AdminServiceDisplayManager::displayAllOrderItems(){
// 	auto orders = BackendService::getInstance().getAllOrders();
// 	// cout<<"whatthaafaaack";
// 	// for(auto item : orders){
// 	// 	displayOrderItem(item);
// 	// }
// }