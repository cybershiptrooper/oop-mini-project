#pragma once
#include "productManager.h"
#include <vector>
#include <map>
#include <memory>
#include "customerParser.h"
#include "customerManager.h"
#include "productParser.h"
#include "orderItemParser.h"
// #include "orderItemManager.h"

class BackendService {
private:
	
	BackendService(){
		CustomerParser::getInstance().readFile();
        ProductParser::getInstance().readFile();
        OrderItemParser::getInstance().readFile();
    };
	BackendService(const BackendService& bs) = delete;
	BackendService& operator=(const BackendService& bs) = delete;
    ProductManager &PM = ProductManager::getInstance();
	CustomerManager &CM = CustomerManager::getInstance();
    OrderItemManager &OM = OrderItemManager::getInstance();
public:
	static BackendService& getInstance(){
		static BackendService BS;
		return BS;
	}
    
    shared_ptr<ProductWrapper> searchProduct(string name){return PM.searchProduct(name);}
    shared_ptr<ProductWrapper> searchProduct(string name, int choice){
        string category = getCategory(choice); 
        return PM.searchProduct(name, category);
    }
    
    map<string, vector<shared_ptr<ProductWrapper>>> getAllProds(){return PM.getCatalouge();}
    
    auto& getProductsOfCategory(string category){return PM.getCatalouge()[category];}
    auto& getProductsOfCategory(int choice){
        string category = getCategory(choice); 
        return PM.getCatalouge()[category]; 
    }

    string getCategory(int choice);
    void addProduct(string name, double cost, string category, int stock);
    bool createCategory(string category){return PM.createCategory(category);}
    unsigned int getProductSize(){return PM.getCatalouge().size();}

    shared_ptr<OrderItem> createOrderItem(
            shared_ptr<Customer> customer,
	        shared_ptr<ProductWrapper> product,
	        int qty,
	        char* tm);
    bool checkCanBuy(shared_ptr<ProductWrapper> product, int qty){
        return (product->getStock() >= qty);
    };
};