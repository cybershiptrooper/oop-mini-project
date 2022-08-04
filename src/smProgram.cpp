#include "smProgram.h"
#include "smProgramDisplayManager.h"

int SMProgramDisplayManager::displayStartMenu(){
	cout<<"Please enter the interface to access:\n 1. Store Representative Interface\n 2. Admin Interface\n 3. Exit\n --> ";
	int choice = getChoice(3);
	if(choice == -1) return displayStartMenu();
	return choice;
}

void SMProgram::start(){
	cout<<"Welcome to your Store Manager.\n";
	while(true){
		int choice = SMProgramDisplayManager().displayStartMenu();
		switch (choice)
		{
		case 1:
			cout << "Welcome to customer services.\n";
			CustomerService().start();
			break;
		case 2:
			cout << "Welcome to admin services.\n";
			AdminService().start();
			break;
		default:
			cout<<"Thank you for using Store Manager\n";
			return;
		}
	}

}