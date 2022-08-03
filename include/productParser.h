#include <string>
using namespace std;

class ProductParser
{
private:
    const string file_name;
    ProductParser() : file_name("data/Product.data"){};
    ProductParser(const ProductParser &s) = delete;
    ProductParser &operator=(const ProductParser &s) = delete;

public:
    string setFileName() { return file_name; };
    static ProductParser &getInstance()
    {
        static ProductParser CP;
        return CP;
    }
    bool read();
    bool write();
};
