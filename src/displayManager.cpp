#include "displayManager.h"

int DisplayManager::getChoice(const unsigned int max_choices){
		int choice;
		try{
			cin >> choice;
			cout << linebreak;
			if(choice > max_choices or choice < 1){
				throw "No such option found";
			}
		}
		catch(...){
			cout<<"Please select a valid option\n";
			return -1;
		}
		return choice;
}