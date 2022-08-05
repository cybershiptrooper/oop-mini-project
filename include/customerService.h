#include "customerServiceDisplayManager.h"
#include "frontendService.h"
#include "cart.h"

class CustomerService: public FrontendService
{
private:
	CustomerServiceDisplayManager* getDM(){
		return &(*dynamic_pointer_cast<CustomerServiceDisplayManager>(DM));
		}
public:
	CustomerService(): FrontendService(Representative){
		 DM = make_shared<CustomerServiceDisplayManager>();
	};

	void start();
	void customerInterface();
	void cartManager();
};

