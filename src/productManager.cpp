#include <iostream>
#include "productManager.h"

using namespace std;

shared_ptr<ProductWrapper> ProductManager::searchProduct(string prodName)
{
    for (auto i : registeredProducts)
    {
        for (auto j : i.second)
        {
            if (j->getProduct()->getName() == prodName)
            {
                return j;
            }
        }
    }
    return NULL;
}

void ProductManager::addProduct(shared_ptr<ProductWrapper> p)
{

    registeredProducts[p->getCategory()].push_back(p);
    return;
}

void ProductManager::DisplayProduct(shared_ptr<ProductWrapper> p)
{
    cout << "Name: " << p->getProduct()->getName() << endl;
    cout << "Cost: " << p->getProduct()->getCost() << endl;
    cout << "Category: " << p->getCategory() << endl;
    cout << "Stock: " << p->getStock() << endl;

    return;
}

void ProductManager::deleteProduct(string name, string cat = "")
{
    if (cat != "")
    {
        for (auto it = (registeredProducts[cat]).begin(); it != (registeredProducts[cat]).end(); it++)
        {
            if ((*it)->getProduct()->getName() == name)
                (registeredProducts[cat]).erase(it);
        }
    }
    else
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
}
