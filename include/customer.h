#pragma once
#include <string>
using namespace std;

class Customer{
	private:
		string name;
		string address; //make a struct
		string phone; //make a struct
	public:
		Customer(const string name, const string address, const string phone): name(name), address(address), phone(phone){};
		string getName(){return name;};
		string getAddress(){return address;};
		string getPhone(){return phone;};
		void updateAddress(string addr){address = addr;};
		void updatePhone(char* no){phone = no;};//add exce

};


// TODO:
// Add Exceptions for phone (Outside in customer service)
// Add struct for phone, Address