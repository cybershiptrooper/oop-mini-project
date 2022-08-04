#include "iowriter.h"
#include "iostream"
using namespace std;

bool testIOWriterClass(){
	cout << "Testing IOWriter class\n";

	string hunter = "I am a hunter";
	string boy = "I am a boy";
	string man = "I am a man now";
	list<string> ques = {hunter, man, boy};
	remove("demo.log");
	
	// Read/Write
	// cout << "  Testing IOWriter read/write\n";
	// writer.append(hunter);
	// // cout << "  1\n";
	// writer.append(boy);
	// // cout << "  2\n";
	// auto ansl = writer.readFromBeginning();
	// // cout << "  R\n";
	// vector<string> ans1;
	// for(auto i : ansl){ans1.push_back(i);}
	// assert(ans1.size() == 3);
	// assert(ans1[0] == hunter);
	// assert(ans1[1] == boy);
	// assert(ans1.size() == 3);
	// // Replace 
	// cout << "  Testing IOWriter replace\n";
	// writer.replaceLine(2, man);
	// ansl = writer.readFromBeginning();
	// vector<string> ans2;
	// for(auto i : ansl){ans2.push_back(i);}
	// assert(ans2[0] == hunter);
	// assert(ans2[1] == man);
	// assert(ans2.size() == 3);
	// // Delete
	// cout << "  Testing IOWriter delete\n";
	// writer.deleteLine(2);
	// ansl = writer.readFromBeginning();
	// vector<string> ans3;
	// for(auto i : ansl){ans3.push_back(i);}
	// assert(ans3[0] == hunter);
	// assert(ans3.size() == 2);
	IOWriter writer("demo.log");
	writer.writeFromBeginning(ques);
	list<string> ans = writer.readFromBeginning();
	assert(ques == ans);
	cout << "Testing completed\n";
	return true;
}