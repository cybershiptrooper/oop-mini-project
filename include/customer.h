#include <string>
using namespace std;

class Customer{
	private:
		string name;
		string address; //make a struct
		char* phone; //make a struct
	public:
		Customer(string name, string address, char* phone): name(name), address(address), phone(phone){};
		string getName(){return name;};
		string getAddress(){return address;};
		char* getPhone(){return phone;};
		void updateAddress(string addr){address = addr;};
		void updatePhone(char* no){phone = no;};//add exce

};


// TODO:
// Add Exceptions for phone (Outside in customer service)
// Add struct for phone Address