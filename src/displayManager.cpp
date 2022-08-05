#include "displayManager.h"

int DisplayManager::getChoice(const unsigned int max_choices){
		int choice;
		try{
			cin >> choice;
			// cout << linebreak;
			if(choice > max_choices or choice < 1){
				throw "No such option found";
			}
		}
		catch(...){
			cout<<"Please select a valid option\n";
			clearCIN();
			return -1;
		}
		return choice;
}

bool DisplayManager::getBoolChoice(){
	char choice;
	cin >> choice;
	if(choice !='Y' and choice != 'y' and choice !='N' and choice != 'n'){
		clearCIN();
		throw std::invalid_argument("No such option found");
	}
	// cout << linebreak;
	return choice;
}

int DisplayManager::displayProductCategoryMenu(User user, bool create){
	if(create){
		try{
			if(user != Admin) throw "User not an admin";
		}
		catch(...){cout<<"You do not have the permission to dit product categories.";};
	}

	int max_choices = BackendService::getInstance().getProductSize();
	if(max_choices == 0 and !create){cout<<"Store is empty!\n"<<linebreak; return -1;}
	cout<<"Select a product category\n";
	int i = 1;
	for(auto item : BackendService::getInstance().getAllProds()){
		cout<<i++<<". "<< item.first <<"\n";
	}
	
	if(create){
		max_choices++;
		cout<<max_choices<<". Create a new category of product"<<"\n";
	}

	int choice = getChoice(max_choices);
	if(choice == -1) return displayProductCategoryMenu(user, create);
	return choice;
}

string DisplayManager::getName(string dataItem, string prefix){
	cout<<linebreak<<prefix<<dataItem<<":\n";
	string str;
	// clearCIN();
	// getline(cin, str);
	cin>>str;
	return str;
}

void DisplayManager::displayProduct(shared_ptr<ProductWrapper> p)
{
    cout << "Name: " << p->getProduct()->getName() << endl;
    cout << "Cost: " << p->getProduct()->getCost() << endl;
    cout << "Category: " << p->getCategory() << endl;
    cout << "Stock: " << p->getStock() << endl<<endl;
}

void DisplayManager::displayProducts(){
	int i = 1;
	for(auto item : BackendService::getInstance().getAllProds()){
		for(auto product : item.second){
			cout<<i++<<". ";
			displayProduct(product);
		}
	}
	cout<<linebreak;
}

void DisplayManager::displayProducts(string category){
	int i = 1;
	for(auto product : BackendService::getInstance().getAllProds()[category]){
		cout<<i++<<". ";
		displayProduct(product);
	}
	cout<<linebreak;
}
// bool DisplayManager::displayManageProductMenu(shared_ptr<ProductWrapper> product)