
#include <string>
#include <map>
#include <Product.h>
using namespace std;

class ProductWrapper
{
    Product *product;
    // shared_ptr<Product> product;
    const unsigned int productID;
    string category;
    int stock;
    static map<string, int> category_map;

public:
    ProductWrapper(double productID, string category, int stock, string name, double cost) : productID(productID), category(category), stock(stock)
    {
        product = new Product(name, cost);
        if (category_map.find(category) == category_map.end())
        {
            category_map[category] = category_map.size();
        }
    }
    ~ProductWrapper() { delete product; }

    double getID() { return productID; }
    int getCategoryNum()
    {
        return category_map[category];
    }
    int getStock() { return stock; }
    Product *getProduct() { return product; }
};

map<string, int> ProductWrapper::category_map = map<string, int>();

// TODO
// category int mapping