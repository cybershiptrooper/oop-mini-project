#include <string>
using namespace std;

class CustomerParser
{
private:
	const string file_name;
	CustomerParser(): file_name("data/customer.data"){};
	CustomerParser(const CustomerParser& s) = delete;
	CustomerParser& operator=(const CustomerParser& s) = delete;
public:
	string setFileName(){return file_name;};
	static CustomerParser& getInstance(){
		static CustomerParser CP;
		return CP;
	}
	bool read();
	bool write();

};
