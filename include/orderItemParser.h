#include <string>
using namespace std;

class OrderItemParser
{
private:
	const string file_name;
	OderItemParser(): file_name("data/orderitem.data"){};
	//OrderItemParser(const OrderItemParser& s) = delete;
	//OrderItemParser& operator=(const OrderItemParser& s) = delete;
public:
    ~OderItemParser();
	string getFileName(){return file_name;};
	static OrderItemParser& getInstance(){
		static OrderItemParser OP;
		return OP;
	}
    void deleteInstance();
	bool read();
	bool write();

};

//TODO - destructor, deleteInstance()