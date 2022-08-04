#include "BackendService.h"
#include "productManager.h"
// #include "orderItemManager.h"

class BackendService
{
private:
	BackendService(){};
	BackendService(const BackendService& s) = delete;
	BackendService& operator=(const BackendService& s) = delete;
	
public:
	static BackendService& getInstance(){
		static BackendService CM;
		return CM;
	}
};