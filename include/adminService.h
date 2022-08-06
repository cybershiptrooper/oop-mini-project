#include "adminServiceDisplayManager.h"
#include "frontendService.h"

class AdminService: FrontendService
{
private:
	AdminServiceDisplayManager* getDM(){
		return &(*dynamic_pointer_cast<AdminServiceDisplayManager>(DM));
		}
public:
	AdminService(): FrontendService(Admin){
		 DM = make_shared<AdminServiceDisplayManager>();
	};
	void start();
	void addNewProduct();
	void viewInventoryStats(shared_ptr<ProductWrapper> product);
	void manageProduct(shared_ptr<ProductWrapper> product);
};

