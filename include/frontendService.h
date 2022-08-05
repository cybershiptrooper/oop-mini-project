#pragma once
#include "displayManager.h"
#include "constants.h"
#include <memory>
#include "backendService.h"
using namespace std;
class FrontendService
{
protected:
	shared_ptr<DisplayManager> DM;
	User user;
	virtual DisplayManager* getDM(){return &(*DM);};
public:
	FrontendService(User user): user(user){};
	void searchProduct();
	void displayProducts();
	virtual void start() = 0;
	
};

