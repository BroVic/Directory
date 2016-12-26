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
*	fileIps.h
*/

#ifndef FILEIPS_H_INCLUDED
#define FILEIPS_H_INCLUDED
class fileIps{
private:
	unsigned i, j;
protected:
	ofstream ontoFile;
	string new_string;
	string new_title, new_intercomNum, new_dept;
public:
	fileIps()
	{ // default constructor
		ontoFile.open("example.txt", ios::in | ios::app);
	}
	fileIps(string);
	fileIps(string, string, string);
    ~fileIps()
	{
		ontoFile.close(); 
	}
	
	// function declarations
	/* bool validate(); */		// DEPRECATED
	void create_string();
	void write_string();
};
#endif // FILEIPS_H_INCLUDED

 fileIps::fileIps(string str = "Default string")
 {							// assignment constructor
	ontoFile.open("example.txt", ios::in | ios::app);
	new_string = str;
} 

 fileIps::fileIps(string a, string b, string c)
 {
	 ontoFile.open("example.txt", ios::in | ios::app);
	 new_title = a;
	 new_intercomNum = b;
	 new_dept = c;
 }

 /*
 **** DEPRECATED ****
 // check whether file opening is successful
 bool fileIps::validate()
 {
	 if (ontoFile.is_open())
		 return false;
	 else
	 {
		 std::cout << "Could not open the file" << std::endl;
		 return true;
	 }
 }
 **********************
 */
 void fileIps::create_string()
 {
	 new_string = new_title;
	 new_string.append(",");
	 new_string.append(new_intercomNum);
	 new_string.append(",");
	 new_string.append(new_dept);
	 return;
 }

 void fileIps::write_string() {
	 if (ontoFile.is_open())
	 {
		 if (!new_string.empty())
			 ontoFile << new_string;
		 else if (new_string.empty())
			 cout << "Error: String entry not read internally.";
	 }
	 else cout << "Error: File could not be opened.";
	 return;
 }

