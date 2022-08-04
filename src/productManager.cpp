#include "ProductManager.h"

shared_ptr<ProductWrapper> ProductManager::searchProduct(string prodName){
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

void ProductManager::addProduct(shared_ptr<ProductWrapper> p){
	
        registeredProducts[p->getCategory()].push_back(p);
        return;
}


void ProductManager::deleteProduct(string name){

        for (auto i : registeredProducts)
        {
            for (auto j : i.second)
            {
                if (j->getProduct()->getName() == name)
                {   
                    // auto it = find(i.second.begin(), i.second.end(), j);
                    // cout<<*it<<endl;
                    // i.second.erase(it);
                    // // std::iter_swap(it, i.second.end());
                    // // i.second.pop_back();
                    i.second.erase(std::remove(i.second.begin(), i.second.end(), j), i.second.end());
                    break;
                }
            }
        }
    }

