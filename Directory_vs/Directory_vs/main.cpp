#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include"Record.h"
#include"fileOps.h"
#include"fileIps.h"
#include"AllRecords.h"
#include"SelectRecords.h"
using namespace std;

int main() {
	char trigger{};
	int options = 0;
	bool testing{};

	printf("%s", "Enter 1 to WRITE DATA or enter 2 to READ DATA:\n");
	cin >> options;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (options == 1)
	{
		// for entering new data
		string ext_title, ext_intercomNum, ext_dept;

		printf("%s", "Enter Officer's Title:\n");
		getline(cin, ext_title);
		printf("%s", "Enter Officer's Intercom Number:\n");
		getline(cin, ext_intercomNum);
		printf("%s", "Enter Officer's Department:\n");
		getline(cin, ext_dept);
		
		fileIps Inptbox(ext_title, ext_intercomNum, ext_dept);
		
		Inptbox.create_string();
		testing = Inptbox.validate();
		if (testing == true)
			return -1;
		else if (testing == false)
			Inptbox.write_string();
	}
	else if (options == 2)
	{
		fileOps *RdWrt;            // for reading and using data
		AllRecords All;
		SelectRecords Some;

		printf("%s", "To print selected records, type 1. To print all records, type 2:\n");
		cin >> options;
		if (options == 1) {
			// Look for selected records
			RdWrt = &Some;
			testing = RdWrt->validate();
			if (testing == true) { return -1; }
			RdWrt->printOut();
		}
		else if (options == 2) {
			// To print out all items in the database
			RdWrt = &All;
			testing = RdWrt->validate();
			if (testing == true) { return -1; }
			cout << "You selected " << options << "\n ";
			cout << "Do you want to continue {Y/N)?: ";
			std::cin >> trigger;
			if (trigger == 'Y' || trigger == 'y') {
				RdWrt->printOut();
			}
			else if (trigger == 'N' || trigger == 'n') {
				cout << "Thank you. Good bye" << endl;
			}
			else { cout << trigger << " is not a valid entry. Exiting the application." << endl; }
		}
		else { cout << "Invalid entry. Ending the program." << endl; }
	}

	return 0;
}
