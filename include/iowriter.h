#pragma once
#include <fstream>
#include <string>
#include <list>

using namespace std;

class IOWriter
{
private:
	const string filename;
	// int lineNo;
	// void editLine(const unsigned int num, const string edited);
public:
	IOWriter(const string filename):
	// lineNo(1), 
	filename(filename){
	// file.open(filename, ios::out | ios::app | ios::in);
	};
	// auto readNextLine();
	void append(string line){
		fstream file;
		file.open(filename, ios::out | ios::app);
		file << line << endl;
		file.close();
	};
	// void replaceLine(const unsigned int num, const string edited);
	// void deleteLine(const unsigned int num);
	// unsigned int getLineNo(){return lineNo;};
	// void gotoLine(const unsigned int num);
	// void goToEOF();
	// bool readIsFinished(){return file.eof();};
	list<string> readFromBeginning();
	void writeFromBeginning(list<string> data);
};

//Exception filename
//Exception file reached ending => file.clear
//Exeption isopen
//Exeptions for lineNo > 0
//replace asserts in cpp
//Should we use templates here?