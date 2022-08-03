
#include <string>
#include <map>
#include <Product.h>
using namespace std;

class ProductWrapper
{
    Product *product;
    const unsigned int productID;
    int stock;

public:
    ProductWrapper(double productID, int stock, string name, double cost) : productID(productID), stock(stock)
    {
        product = new Product(name, cost);
        
    }
    ~ProductWrapper() { delete product; }

    double getID() { return productID; }
    
    int getStock() { return stock; }
    Product *getProduct() { return product; }
};




// TODO
// category int mapping