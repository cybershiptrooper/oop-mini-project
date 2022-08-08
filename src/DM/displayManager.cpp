#include "displayManager.h"
#include <assert.h>
int DisplayManager::getChoice(const unsigned int max_choices){
		int choice;
		try{
			string in;
			getline(cin, in);
			choice = stoi(in);
			// cout << linebreak;
			if(choice > max_choices or choice < 1){
				throw std::invalid_argument("No such option found");
			}
		}
		catch(...){
			cout<<"Please select a valid option\n";
			// clearCIN();
			choice = -1;
		}
		return choice;
}

bool DisplayManager::getBoolChoice(){
	char choice;
	bool ans;
	cin >> choice;
	clearCIN();
	if(choice =='Y' or choice == 'y') return true;
	if(choice =='N' or choice == 'n') return false;
	cout<<"Please select a valid option\n";
	throw std::invalid_argument("No such option found");
	// cout << linebreak;
	return ans;
}

int DisplayManager::displayProductCategoryMenu(User user, bool create){
	if(create){
		if(user != Admin){ 
			cout<<"You do not have the permission to edit product categories.";
			return -1;
		}
	}
	int choice;
	while(true){
		int max_choices = BackendService::getInstance().getProductSize();
		if(max_choices == 0 and !create){cout<<"Store is empty!\n"; return -1;}
		
		cout<<"Select a product category\n";
		int i = 1;
		for(auto item : BackendService::getInstance().getAllProds()){
			cout<<i++<<". "<< item.first <<"\n";
		}
		
		if(create){
			max_choices++;
			cout<<max_choices<<". Create a new category of product"<<"\n";
		}
		// else{
		// 	max_choices++; cout<<max_choices<<". All categories"<<"\n";
		// }
		
		choice = getChoice(max_choices);
		// throw std::logic_error(to_string(choice));
		if(choice > 0) break;
	}			
	return choice;
}

string DisplayManager::getName(string dataItem, string prefix){
	cout<<prefix<<dataItem<<":\n";
	string str;
	getline(cin, str);
	return str;
}

int DisplayManager::getNumber(string dataItem){
	int ans;
	while(true){
		try{
			std::string query = "Please enter the ";
			ans = stoi(getName(dataItem, query));
			if(ans < 0) throw std::invalid_argument("incorrect qty");
			break;
		}
		catch(...){
			clearCIN();
			cout<<"Please enter a non-negative integer\n";
		}
	}
	return ans;
}

double DisplayManager::getFloatingNumber(string dataItem){
	double ans;
	while(true){
		try{
			std::string query = "Please enter the ";
			ans = stod(getName(dataItem, query));
			if(ans < 0) throw std::invalid_argument("incorrect qty");
			break;
		}
		catch(...){
			clearCIN();
			cout<<"Please enter a non-negative numeric quantity\n";
		}
	}
	return ans;
}

void DisplayManager::displayProduct(shared_ptr<ProductWrapper> p)
{	
	//cerr<<"DM"<<&(*p)<<endl;
	assert(p->getProduct() != nullptr);
    cout << "Name: " << p->getProduct()->getName() << endl;
    cout << "Cost: " << p->getProduct()->getCost() << endl;
    cout << "Category: " << p->getCategory() << endl;
    cout << "Stock: " << p->getStock() << endl<<endl;
}

void DisplayManager::displayProduct(shared_ptr<Product> p)
{
    cout << "Name: " << p->getName() << endl;
    cout << "Cost: " << p->getCost() << endl;
}

void DisplayManager::displayProducts(){
	int i = 1;
	//cerr<<BackendService::getInstance().getAllProds().size()<<endl;
	for(auto item : BackendService::getInstance().getAllProds()){
		//cerr<<item.second.size()<<endl;
		for(auto product : item.second){
			cout<<i++<<". ";
			displayProduct(product);
		}
	}
	// cout<<linebreak;
}

void DisplayManager::displayProducts(string category){
	int i = 1;
	// cerr<<(BackendService::getInstance().getAllProds()[category]).size()<<endl;
	auto li = BackendService::getInstance().getAllProds()[category];
	for(auto it = li.begin(); it != li.end(); it++ ){
		cout<<i++<<". ";
		displayProduct(*it);
	}
	// cout<<linebreak;
}

void DisplayManager::displayCustomer(shared_ptr<CustomerWrapper> customer){
	cout << "Name: " <<  customer->getCustomer()->getName() << endl;
    cout << "Phone: " << customer->getCustomer()->getPhone() << endl;
    cout << "Address: " << customer->getCustomer()->getAddress() << endl;
    cout << "Membership: " << ToString(customer->getMembership()->getType()) << endl<<endl;
}

void DisplayManager::displayCustomer(shared_ptr<Customer> customer){
	cout << "Name: " <<  customer->getName() << endl;
    cout << "Phone: " << customer->getPhone() << endl;
    cout << "Address: " << customer->getAddress() << endl;
    // cout << "Membership: " << customer->getMembership()->getType() << endl<<endl;
}

void DisplayManager::displayOrderItem(shared_ptr<OrderItem> item){
	cout << "ID: " << item->getID() << endl;
    cout << "Customer: \n"; 
	displayCustomer(item->getCustomer());
    cout << "Product: \n";
	displayProduct(item->getProduct()); 
    // cout << "Stock: " << p->getStock() << endl<<endl;
}

// bool DisplayManager::displayManageProductMenu(shared_ptr<ProductWrapper> product)