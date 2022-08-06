#include "displayManager.h"

class AdminServiceDisplayManager: public DisplayManager
{
private:
public:
	int displayStartMenu();
	void displayAllOrderItems();
	int displayManageProductMenu(shared_ptr<ProductWrapper> product);
};