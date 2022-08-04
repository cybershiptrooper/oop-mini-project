#include "iowriter.h"
#include <limits>
#include <assert.h>

// auto IOWriter::readNextLine(){
// 	string s;
// 	if(file.eof()) return s;
// 	getline(file, s);
// 	return s;
// }

// void IOWriter::editLine(const unsigned int num, const string edited){
// 	fstream temp;
// 	temp.open("temp.log", ios::out | ios::trunc | ios::in);
// 	string line;
// 	file.seekg(ios::beg);
// 	lineNo = 1;
// 	while (getline(file,line))
// 	{
// 		if(lineNo++==num) temp << edited;
// 		else temp << line << endl;
// 	}
// 	temp.close();
// 	file.close();
// 	char* path = const_cast<char*>(filename.c_str());
// 	remove(path);
// 	rename("temp.log", path);
// 	file.open(filename, ios::out | ios::in);
// }

// void IOWriter::replaceLine(const unsigned int num, const string edited){
// 	string s = edited + "\n";
// 	editLine(num, s);
// }

// void IOWriter::deleteLine(const unsigned int num){
// 	editLine(num, "");
// }

// void IOWriter::gotoLine(const unsigned int num){
// 	file.seekg(ios::beg);
// 	assert(num > 0);
// 	for(int i=0; i < num - 1; ++i){
//         file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//     }
// 	lineNo = num;
// }

// void IOWriter::goToEOF(){
// 	file.seekg(ios::beg);
// 	lineNo = 1;
// 	while(!file.eof()){
// 		lineNo++;
// 		file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
// 	}

// }
void IOWriter::writeFromBeginning(list<string> data){
	fstream file;
	// file.close();
	file.open(filename, ios::out | ios::trunc);
	for(string i : data){
		file<<i<<endl;
	}
	file.close();
	
}

list<string> IOWriter::readFromBeginning(){
	fstream file;
	file.open(filename, ios::out | ios::app | ios::in);
	file.seekg(ios::beg);
	list<string> ans;
	while(!file.eof()){
		string s;
		getline(file, s);
		ans.push_back(s);
	}
	// file.clear();
	// file.seekg(ios::beg);
	// lineNo = 1;
	file.close();
	return ans;

}