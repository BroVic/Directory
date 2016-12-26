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
*	main.cpp
*/

#define _SCL_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>
#include"Record.h"
#include"fileOps.h"
#include"fileIps.h"
#include"AllRecords.h"
#include"SelectRecords.h"
using namespace std;

int main()
{
	int options = 0;
	// bool testing{};

	printf("%s", "Enter 1 to WRITE DATA or enter 2 to READ DATA:\n");
	cin >> options;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (options == 1)										// WRITE DATA
	{
		string ext_title, ext_intercomNum, ext_dept;

		cout << "Enter Officer's Title:\n";
		getline(cin, ext_title);
		cout << "\nEnter Officer's Intercom Number:\n";
		getline(cin, ext_intercomNum);
		cout << "\nEnter Officer's Department:\n";
		getline(cin, ext_dept);
		
		fileIps Inptbox(ext_title, ext_intercomNum, ext_dept);
		
		Inptbox.create_string();
		Inptbox.write_string();
		/* *** DEPRECATED ***
		testing = Inptbox.validate();		
		if (testing == true)
			return -1;
		else if (testing == false)
			Inptbox.write_string();
		*/
	}
	else if (options == 2)									// READ DATA
	{
		fileOps *RdWrt;            

		cout << "To print selected records, type 1. To print all records, type 2:\n";
		cin >> options;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (options == 1)			// Look for selected records
		{
			// User entry
			string entry;
			cout << "Enter Officer's title: ";
			getline(cin, entry);

			SelectRecords Some(entry);
			RdWrt = &Some;

			/* *** DEPRECATED ***
			testing = RdWrt->validate();			
			if (testing == true) { return -1; }
			*/

			RdWrt->printOut();
		}
		else if (options == 2)		// View all available records
		{
			AllRecords All;
			RdWrt = &All;
			char trigger{};

			/**** DEPRECATED ***
			testing = RdWrt->validate();
			if (testing == true)
				return -1;
			*/
			
			cout << "You selected " << options << '\n';
			cout << "Do you want to continue (Y/N)?: ";
			cin >> trigger;
			if (trigger == 'Y' || trigger == 'y')
				RdWrt->printOut();
			else if (trigger == 'N' || trigger == 'n')
				cout << "Thank you. Good bye" << endl;
			else cout << trigger << " is not a valid entry. Exiting the application." << endl;
		}
		else cout << "Invalid entry. Ending the program." << endl;
	}

	return 0;
}
/*

*/