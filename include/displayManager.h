#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "constants.h"
#include "backendService.h"

using namespace std;

class DisplayManager{
	protected:
		string linebreak = "--------------------------\n";
	public: 
		virtual int displayStartMenu()=0;
		int getChoice(const unsigned int max_choices);
		bool getBoolChoice();
		string getName(string dataItem, string prefix = "Please enter the name of the ");
		void createConfirm(string dataItem){cout<<dataItem<<" created!\n";};
		int displayProductCategoryMenu(User user, bool create = false, bool all=false);
		
		void displayProducts(string category);
		void productNotFound(){cout<<"Sorry, but this product is unavailable\n";}
		virtual bool displayManageProductMenu(shared_ptr<ProductWrapper> product){
			displayProduct(product);
			return false;
		};
		void clearCIN(){
			cin.sync();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		void displayProduct(shared_ptr<ProductWrapper> p);
		void displayProducts();
		void displayOrderItem(shared_ptr<OrderItem> item);
		void displayCustomer(shared_ptr<CustomerWrapper> customer);
		void displayCustomer(shared_ptr<Customer> customer);

		void displayProduct(shared_ptr<Product> p);
};

