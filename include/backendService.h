#include "productManager.h"
#include <vector>
#include <map>
#include <memory>
// #include "orderItemManager.h"

class BackendService {
private:
	
	BackendService(){};
	BackendService(const BackendService& bs) = delete;
	BackendService& operator=(const BackendService& bs) = delete;
    ProductManager &pm = ProductManager::getInstance();
	
public:
	static BackendService& getInstance(){
		static BackendService BS;
		return BS;
	}
    
    shared_ptr<ProductWrapper> searchProduct(string name){
        return pm.searchProduct(name);
    }
    map<string, vector<shared_ptr<ProductWrapper>>> dispAllProds(){
        return pm.getCatalouge();
    }

    vector<shared_ptr<ProductWrapper>> dispCategoryProds(string category){
        return pm.getCatalouge()[category];
    }

    void addProd(shared_ptr<ProductWrapper> p){
        pm.addProduct(p);
    }
	
public:
	static BackendService& getInstance(){
		static BackendService CM;
		return CM;
	}
};