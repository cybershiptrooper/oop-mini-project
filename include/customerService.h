#include "customerServiceDisplayManager.h"

class CustomerService
{
private:
	CustomerServiceDisplayManager DM;

	CustomerService(){};
	CustomerService(const CustomerService& s) = delete;
	CustomerService& operator=(const CustomerService& s) = delete;
public:
	static CustomerService& getInstance() {

		static CustomerService CS;
		return CS;
	}

	void start(){
		int choice = DM.displayStartMenu();
	}
};

