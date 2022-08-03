#include "adminServiceDisplayManager.h"

class AdminService
{
private:
	AdminServiceDisplayManager DM;

	AdminService(){};
	AdminService(const AdminService& s) = delete;
	AdminService& operator=(const AdminService& s) = delete;
public:
	static AdminService& getInstance() {

		static AdminService CS;
		return CS;
	}

	void start(){
		int choice = DM.displayStartMenu();
	}
};

