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
		int getNumber(string dataItem);
		double getFloatingNumber(string dataItem);

		void BR(){cout<<linebreak;};
		void createConfirm(string dataItem){cout<<dataItem<<" created!\n";};
		void deleteConfirm(string dataItem){cout<<dataItem<<" deleted!\n";};
		void displayProducts(string category);
		void productNotFound(){cout<<"Sorry, but this product is unavailable\n";}
		void productFound(shared_ptr<ProductWrapper> product){
			cout<<"Product Found:\n";
			displayProduct(product);
		}
		void dispAlreadyExists(shared_ptr<ProductWrapper> product){
			cout<<"Product already exists\n";
			displayProduct(product);
		}
		void clearCIN(){
			cin.sync();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}

		int displayProductCategoryMenu(User user, bool create = false);
		void displayProduct(shared_ptr<ProductWrapper> p);
		void displayProducts();
		void displayOrderItem(shared_ptr<OrderItem> item);
		void displayCustomer(shared_ptr<CustomerWrapper> customer);
		void displayCustomer(shared_ptr<Customer> customer);
		void displayProduct(shared_ptr<Product> p);
};

