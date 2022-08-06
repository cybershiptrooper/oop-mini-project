#include "iowriter.h"
#include <limits>
#include <assert.h>
#include <sstream>
#include <iostream>

void IOWriter::writeFromBeginning(list<string> data){
	fstream file;
	// file.close();
	file.open(filename, ios::out | ios::trunc);
	for(auto i = data.begin(); i!=data.end(); i++){
		file<<*i;
		if(i != --data.end()) file<<endl;
	}
	file.close();
	
}

list<string> IOWriter::readFromBeginning(){
	fstream file;
	file.open(filename, ios::in);
	// file.seekg(ios::beg);
	list<string> ans;
	while(!file.eof()){
		string s;
		getline(file, s);
		ans.push_back(s);
		// //cerr<<s;

	}
	
	file.close();
	return ans;

}