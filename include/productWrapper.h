#pragma once
#include <string>
#include <map>
#include <memory>
#include "product.h"
using namespace std;

class ProductWrapper
{
    shared_ptr<Product> product;
    int stock;
    string category;

public:
    ProductWrapper(const string name, const double cost, const string category, const int stock) :  category(category), stock(stock) { product = shared_ptr<Product>(new Product(name, cost)); };
    ~ProductWrapper(){};

    int getStock() { return stock; }
    void updateStock(int newStock) { stock = newStock; }
    auto getProduct() { return product; }
    auto getCategory(){return category;}
    
};

// TODO
// category int mapping