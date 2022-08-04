#pragma once
#include "productWrapper.h"
#include <vector>
#include <map>
// #include "ProductParser.h"

class ProductManager
{
private:
    shared_ptr<ProductWrapper> p;
    map<string, vector<shared_ptr<ProductWrapper>>> registeredProducts;
    ProductManager() : p(nullptr), registeredProducts(map<string, vector<shared_ptr<ProductWrapper>>>()) {}
    ProductManager(const ProductManager &s) = delete;
    ProductManager &operator=(const ProductManager &s) = delete;

public:
    static ProductManager &getInstance()
    {
        static ProductManager PM;
        return PM;
    }
    
    shared_ptr<ProductWrapper> searchProduct(string productName);
    void addProduct(shared_ptr<ProductWrapper> p);
    map<string, vector<shared_ptr<ProductWrapper>>> getCatalouge() { return registeredProducts; }
    void deleteProduct(string name, string cat="");
    void DisplayProduct(shared_ptr<ProductWrapper> p);

};
