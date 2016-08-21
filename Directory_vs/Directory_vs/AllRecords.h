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
*	AllRecords.h
*/

#ifndef ALLRECORDS_H_INCLUDED
#define ALLRECORDS_H_INCLUDED
class AllRecords :public fileOps {
private:
	unsigned serialNo;
	char brk;
public:
	// Constructors/Deconstructor
	AllRecords(); 
	~AllRecords() { }

	virtual bool validate();
	virtual void printOut();           // for printing all existing records
};
#endif // ALLRECORDS_H_INCLUDED

// Function definitions
AllRecords::AllRecords()
{
	serialNo = 1;
	brk = ' ';
}
bool AllRecords::validate()
{
	if (fromFile.is_open())
		return false;
	else
	{
		cout << "Could not open to print EXISTING records" << endl;
		return true;
	}
}

void AllRecords::printOut() { 
	collectStrings();
	while (!fromFile.eof())
	{
		splitString();
		std::cout << serialNo << brk << title << brk << intercomNum << brk << dept << endl;
		collectStrings();
		serialNo++;
	}
	cout << "\nAll available records have been printed out.\n" << endl;
	return;
}