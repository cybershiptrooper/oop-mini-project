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
		const string getName() const {return name;};
		string getAddress(){return address;};
		const string getPhone() const {return phone;};
		void updateAddress(string addr){address = addr;};
		void updatePhone(string no){phone = no;};//add exce
		bool operator==(const Customer c1){return (getPhone() == c1.getPhone()); };
};


// TODO:
// Add Exceptions for phone (Outside in customer service)
// Add struct for phone, Address