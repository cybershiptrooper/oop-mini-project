#include "smprogram.h"

void SMProgram::start(){
	while(true){	
		cout<<"Welcome to your Store Manager.\nPlease enter the interface to access:\n 1. Store Representative Interface\n 2. Admin Interface\n 3. Exit\n --> ";
		int choice;
		std::cin>>choice;
		switch (choice)
		{
		case 1:
			CustomerService::getInstance().start();
			break;
		case 2:
			AdminService::getInstance().start();
			break;
		default:
			cout<<"Thank you for using Store Manager\n";
			return;
		}
	}

}