#include "iowriter.h"
#include "iostream"
using namespace std;

bool testIOWriterClass(){
	cout << "Testing IOWriter class\n";

	string hunter = "I am a hunter";
	string boy = "I am a boy";
	string man = "I am a man now";

	remove("demo.log");
	IOWriter writer("demo.log");
	// Read/Write
	writer.append(hunter);
	writer.append(boy);
	auto ans = writer.readFromBeginning();
	assert(ans.size() == 3);
	ans = writer.readFromBeginning();
	assert(ans[0] == hunter);
	assert(ans[1] == boy);
	assert(ans.size() == 3);
	// Replace 
	writer.replaceLine(2, man);
	ans = writer.readFromBeginning();
	assert(ans[0] == hunter);
	assert(ans[1] == man);
	assert(ans.size() == 3);
	// Delete
	writer.deleteLine(2);
	ans = writer.readFromBeginning();
	assert(ans[0] == hunter);
	assert(ans.size() == 2);

	cout << "Testing completed\n";
	return true;
}