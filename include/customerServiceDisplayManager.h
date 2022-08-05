#pragma once
#include "displayManager.h"

class CustomerServiceDisplayManager: public DisplayManager
{
private:
public:
	int displayStartMenu();
	bool getExitConfirmation(){return true;};
	bool displayManageProductMenu(shared_ptr<ProductWrapper> product);
};

