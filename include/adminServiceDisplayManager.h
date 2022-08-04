#include "displayManager.h"

class AdminServiceDisplayManager: public DisplayManager
{
private:
	// AdminServiceDisplayManager() {};
	// AdminServiceDisplayManager(const AdminServiceDisplayManager& s) = delete;
	// AdminServiceDisplayManager& operator=(const AdminServiceDisplayManager& s) = delete;
public:
	// static AdminServiceDisplayManager& getInstance() {

	// 		static AdminServiceDisplayManager DM;
	// 		return DM;
	// 	}
	int displayStartMenu();
};