#include "productWrapper.h"
#include <vector>
#include <map>
// #include "customerParser.h"

class ProductManager
{
private:
    ProductWrapper *p;
    map<string, vector<ProductWrapper *>> registeredProducts;
    ProductManager() : p(nullptr), registeredProducts(map<string, vector<ProductWrapper *>>()) {}
    static ProductManager *pm;

public:
    static ProductManager *CreateInstance()
    {
        if (pm == NULL)
            pm = new ProductManager();
        return pm;
    }

    static void DeleteInstance()
    {
        if (pm)
            delete pm;
    }
    // ProductManager(): p(nullptr), registeredProducts(map<string, vector<ProductWrapper*> >()){}
    ~ProductManager() {}

    ProductWrapper *searchProduct(string productName)
    {
        for (auto i : registeredProducts)
        {
            for (auto j : i.second)
            {
                if (j->getProduct()->getName() == productName)
                {
                    return j;
                }
            }
        }
        return NULL;
    }

    void deleteProduct()
    {
        delete[] p;
    }

    void addProduct(string name, double cost, string category, double productID, int stock)
    {
        ProductWrapper *p1 = new ProductWrapper(productID, stock, name, cost);
        registeredProducts[category].push_back(p1);
        return;
    }

    ProductWrapper *getCatalouge()
    {
        return p;
    }
};

ProductManager *ProductManager::pm = NULL;