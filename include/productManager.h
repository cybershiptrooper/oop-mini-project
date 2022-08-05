#pragma once
#include "productWrapper.h"
#include <vector>
#include <map>
// #include "ProductParser.h"

class ProductManager
{
private:
    map<string, vector<shared_ptr<ProductWrapper>>> registeredProducts;
    ProductManager() {};
    ProductManager(const ProductManager &s) = delete;
    ProductManager &operator=(const ProductManager &s) = delete;

public:
    static ProductManager &getInstance()
    {
        static ProductManager PM;
        return PM;
    }
    
    shared_ptr<ProductWrapper> searchProduct(string productName);
    shared_ptr<ProductWrapper> searchProduct(string productName, string category);
    void addProduct(shared_ptr<ProductWrapper> p);
    map<string, vector<shared_ptr<ProductWrapper>>>& getCatalouge() { return registeredProducts; }
    void deleteProduct(string name);
    bool categoryExists(string category);
    bool createCategory(string category);
};
