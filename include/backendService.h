#pragma once
#include "productManager.h"
#include <map>
#include <memory>
#include "customerParser.h"
#include "customerManager.h"
#include "productParser.h"
#include "orderItemParser.h"
#include <iostream>
class BackendService {
private:
	
	BackendService(){
        //cerr<<"constructer Backend\n";
        //cerr<<"Product Parser\n";
        ProductParser::getInstance().readFile();
        //cerr<<"Customer Parser\n";
		CustomerParser::getInstance().readFile();
        //cerr<<"Order Parser\n";
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
    shared_ptr<ProductWrapper> searchProduct(string name, string category){
        return PM.searchProduct(name, category);
    }
    shared_ptr<ProductWrapper> searchProduct(string name, int choice){
        string category = getCategory(choice); 
        return PM.searchProduct(name, category);
    }
    
    map<string, list<shared_ptr<ProductWrapper>>> getAllProds(){
        return ProductManager::getInstance().getCatalouge();
    }
    auto getAllOrders(){return OM.getListOfOrderedItems();}
    auto& getProductsOfCategory(string category){
        return ProductManager::getInstance().getCatalouge()[category];
    }
    auto& getProductsOfCategory(int choice){
        string category = getCategory(choice); 
        return PM.getCatalouge()[category]; 
    }

    string getCategory(int choice);
    shared_ptr<ProductWrapper> addProduct(string name, double cost, string category, int stock);
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

    void deleteProduct(shared_ptr<ProductWrapper> product){
        PM.deleteProduct(product->getProduct()->getName(), product->getCategory());
    }

    void syncProducts(){ProductParser::getInstance().writeFile();}
    void syncOrders(){OrderItemParser::getInstance().writeFile();}
    void syncCustomers(){CustomerParser::getInstance().writeFile();}
    void syncFiles(){syncProducts(); syncOrders(); syncCustomers();}
};