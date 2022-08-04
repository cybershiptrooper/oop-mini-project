#pragma once
#include "displayManager.h"
#include "constants.h"
#include <memory>

class FrontendService
{
protected:
	shared_ptr<DisplayManager> DM;
	User user;
	virtual DisplayManager* getDM(){return &(*DM);};
public:
	FrontendService(User user): user(user){};
	void searchProduct(){/*TODO*/};
	void displayProducts(){/*TODO*/};
	virtual void start() = 0;
	
};

