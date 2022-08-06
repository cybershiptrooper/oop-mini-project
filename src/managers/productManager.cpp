#include <iostream>
#include "productManager.h"
#include <assert.h>
using namespace std;

shared_ptr<ProductWrapper> ProductManager::searchProduct(string prodName)
{
    shared_ptr<ProductWrapper> ans;
    for (auto i : registeredProducts)
    {
        try{
            return searchProduct(prodName, i.first);
        }
        catch(const std::invalid_argument& e){
            continue;
        }
    }
    throw std::invalid_argument( "No such product Exists" );
}

shared_ptr<ProductWrapper> ProductManager::searchProduct(string prodName, string cat){
    
    for (auto j : registeredProducts[cat]){
            if (j->getProduct()->getName() == prodName)
            {
                return j;
            }
    }
    throw std::invalid_argument( "No such product exists" );
}

void ProductManager::addProduct(shared_ptr<ProductWrapper> p)
{
    registeredProducts[p->getCategory()].push_back(p);
    auto prod = (registeredProducts[p->getCategory()]).back();
    assert(prod->getProduct() != nullptr);
    //cerr<<"Manager"<<&(*(prod))<<endl;
}

void ProductManager::deleteProduct(string name, string category)
{   
    for (auto it = (registeredProducts[category]).begin(); it != (registeredProducts[category]).end(); it++)
    {
        if ((*it)->getProduct()->getName() == name){
            (registeredProducts[category]).erase(it);
            break;
        }
    }
}

bool ProductManager::createCategory(string category){
    if(categoryExists(category))return false;
    registeredProducts[category] = {};
    return true;
}

bool ProductManager::categoryExists(string category){
    for(auto item : registeredProducts){
        if(item.first == category) return true;
    }
    return false;
}