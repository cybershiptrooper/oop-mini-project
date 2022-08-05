#include <iostream>
#include "productManager.h"

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
    throw std::invalid_argument( "received negative value" );
}
shared_ptr<ProductWrapper> ProductManager::searchProduct(string prodName, string cat){
    
    for (auto j : registeredProducts[cat]){
            if (j->getProduct()->getName() == prodName)
            {
                return j;
            }
    }
    throw std::invalid_argument( "received negative value" );
}
void ProductManager::addProduct(shared_ptr<ProductWrapper> p)
{
    registeredProducts[p->getCategory()].push_back(p);
    return;
}

void ProductManager::deleteProduct(string name)
{
    
    for (auto category : registeredProducts)
    {
        for (auto it = (registeredProducts[category.first]).begin(); it != (registeredProducts[category.first]).end(); it++)
        {
            if ((*it)->getProduct()->getName() == name)
                (registeredProducts[category.first]).erase(it);
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