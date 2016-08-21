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
*	SelectRecords.h
*/

#ifndef SELECTRECORDS_H_INCLUDED
#define SELECTRECORDS_H_INCLUDED
#include<string>
using namespace std;
class SelectRecords :public fileOps {
private:
	string typed_string;
	unsigned serialNo;
public:
	// Constructor/Deconstructor
	SelectRecords();
	~SelectRecords() { }

	virtual bool validate();  // to check whether memmore was allocated successfully
	virtual void printOut();  // to print out the selected records
};
#endif // SELECTRECORDS_H_INCLUDED

// Function definitions
SelectRecords::SelectRecords() {			// assignment constructor
	typed_string = "No entry made";
	serialNo = serialNo;
}

bool SelectRecords::validate() {
	if (fromFile.is_open())
	{
		return false;
	}
	else
	{
		std::cout << "Could not open to print SELECTED record(s)" << std::endl;
		return true;
	}
}

void SelectRecords::printOut()
{
	// User entry
	cout << "Enter Officer's title: ";		// CONSIDER PUTTING IN THE MAIN FUNCTION
	getline(cin, typed_string);			

	// compare the strings
	collectStrings();
	while (!fromFile.eof())
	{
		if (file_string.compare(typed_string) == 0)
		{
			splitString();
			cout << serialNo << '\t' << title << '\t' << intercomNum << '\t' << dept << '\n';
		}
		collectStrings();
		serialNo++;
	}
}