#pragma once
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class DisplayManager{
	private:
		string linebreak = "--------------------------\n";
	public: 
		virtual int displayStartMenu()=0;
		int getChoice(const unsigned int max_choices);
		
		int displayProductCategoryMenu(User user);
};
