#include "customerServiceDisplayManager.h"
#include "frontendService.h"
#include "cart.h"

class CustomerService: public FrontendService
{
private:
	bool main_flag=false;
	unique_ptr<Cart> cart;
	CustomerServiceDisplayManager* getDM(){
		return &(*dynamic_pointer_cast<CustomerServiceDisplayManager>(DM));
		}
public:
	CustomerService(): FrontendService(Representative), cart(make_unique<Cart>()){
		 DM = make_shared<CustomerServiceDisplayManager>();
	};

	void start();
	void customerInterface();
	void manageCart();
	void manageProduct(shared_ptr<ProductWrapper> product);
	void updateCartQty(shared_ptr<ProductWrapper> product);
	shared_ptr<ProductWrapper> searchProductInCart();
	void resetCart(){cart.reset(new Cart());}
	void editMemberDetail();
};

