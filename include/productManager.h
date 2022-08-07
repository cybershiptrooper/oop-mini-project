#pragma once
#include "productWrapper.h"
#include <list>
#include <map>
#include <iostream>
// #include "ProductParser.h"

class ProductManager
{
private:
    map<string, list<shared_ptr<ProductWrapper>>> registeredProducts;
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
    map<string, list<shared_ptr<ProductWrapper>>>& getCatalouge() { return registeredProducts; }
    void deleteProduct(string name, string category);
    bool categoryExists(string category);
    bool createCategory(string category);
};
