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

// void AdminServiceDisplayManager::displayAllOrderItems(){
// 	auto orders = BackendService::getInstance().getAllOrders();
// 	// cout<<"whatthaafaaack";
// 	// for(auto item : orders){
// 	// 	displayOrderItem(item);
// 	// }
// }