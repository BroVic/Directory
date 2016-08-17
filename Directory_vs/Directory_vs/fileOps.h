#ifndef FILEOPS_H_INCLUDED
#define FILEOPS_H_INCLUDED
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class fileOps :public Record
{
private:
	int i, j;  // counters
protected:
	ifstream fromFile;
	string file_string;
public:
	fileOps() { }
	~fileOps() { fromFile.close(); }

	virtual void printOut() = 0;   // to print output
	virtual bool validate() = 0;   // to validate file opening

	// File operations
	void collectStrings();          // for collecting strings from file
	void splitString();             // for splitting strings into parts
		
};
#endif // FILEOPS_H_INCLUDED

fileOps::fileOps()
{
	fromFile("office-contact.csv");
	file_string;
}

void fileOps::collectStrings() 
{ 
	if (fromFile.is_open)
	{
		while (getline(fromFile, file_string))
		{

		}
	}
	
	return;
}

void fileOps::splitString() 
{
	i = 0; j = 0;
	while ((title[i++] = file_string[j++]) != ',');
	for (; i < 29; i++) title[i - 1] = ' ';
	title[i - 1] = '\0'; i = 0;
	while ((intercomNum[i++] = file_string[j++]) != ',');
	intercomNum[i - 1] = '\0'; i = 0;
	while ((dept[i++] = file_string[j++]) != '\0');
	return;
}