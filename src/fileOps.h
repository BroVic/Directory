/*
*	Copyright (c) 2016 Victor Ordu. All rights reserved.
*
*	The information and source code contained herein is the exclusive
*	property of Victor A. Ordu (victorordu@outlook.com) and may not be disclosed, examined
*	or reproduced in whole or in part without explicit written authorization
*	from the author.
*
*	PURPOSE:
*	A program for an application that will store and retrieve office contact details of staff
*	of the National Environmental Standards and Regulations Enforcement Agency (NESREA) HQ
*	at No. 4, Oro Ago Crescent, Garki II, Abuja, Nigeria.
*
*	fileOps.h
*/

#ifndef FILEOPS_H_INCLUDED
#define FILEOPS_H_INCLUDED
using namespace std;

class fileOps :public Record
{
private:
	size_t comma_pos;
protected:
	ifstream fromFile;
	string file_string;
public:
	fileOps();
	~fileOps() 
	{	// destructor
		fromFile.close();
	}

	virtual void printOut() = 0;   // to print output
	// virtual bool validate() = 0;   // to validate file opening    (*** DEPRECATED ***)

	// File operations
	void collectStrings();          // for collecting strings from file
	void splitString();             // for splitting strings into parts
	void copy_segm(char ARR[]);			//for copying parts of string to base class data members
};
#endif // FILEOPS_H_INCLUDED

fileOps::fileOps()
{
	comma_pos = 0;
	fromFile.open("office-contact.csv", ios::out);
	file_string.clear();
}

void fileOps::collectStrings() 
{ 
	if (fromFile.is_open())
	{
		if (!fromFile.eof())
		{
			getline(fromFile, file_string);
		}
		else
		{
			cout << "End of file - finished reading data.";
		}
	}
	else cout << "Error: Could not open the file.";
	return;
}

void fileOps::copy_segm(char ARR[])
{
	comma_pos = file_string.find(',');
	file_string.copy(ARR, comma_pos, 0);
	file_string.erase(0, ++comma_pos);
	return;
}

void fileOps::splitString() 
{
	copy_segm(title);
	copy_segm(intercomNum);
	file_string.copy(dept, file_string.length(), 0);
	file_string.clear();
	return;
}