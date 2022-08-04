#pragma once
#include "displayManager.h"

class SMProgramDisplayManager: DisplayManager{
	public:
		int displayStartMenu();
		int displayProductCategoryMenu(User user) = delete;
};