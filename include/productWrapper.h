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
    ProductWrapper(
        const string name, const double cost, const string category, const int stock) :  category(category), stock(stock) { product = shared_ptr<Product>(new Product(name, cost)); };
    ~ProductWrapper(){};
    int getStock() { return stock; }
    void updateStock(int newStock) { stock = newStock; }
    auto getProduct() const { return product; }
    auto getCategory() const {return category;}
    void addToStock(int qty){stock += qty;};
    bool operator==(const ProductWrapper p1){
        if(
            (p1.getProduct()->getName() == getProduct()->getName())
            and (p1.getCategory() == getCategory())
        ){ return true;}
        return false;
    };
};

// TODO
// category int mapping