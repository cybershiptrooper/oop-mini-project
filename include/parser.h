#include <string>
using namespace std;

class Parser
{
private:
	const string file;
public:
	Parser(const string file): file(file){};
	virtual void read()=0;
};

