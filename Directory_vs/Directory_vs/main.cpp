#include<iostream>
#include<cstdio>
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

	
	fileIps Inptbox;			// for entering new data
	char ext_title[20]; char ext_intercomNum[4]; char ext_dept[20];

	printf("%s", "Enter Officer's Title:\n");
	gets_s(ext_title, 20);
	printf("%s", "Enter Officer's Intercom Number:\n");
	gets_s(ext_intercomNum, 4);
	printf("%s", "Enter Officer's Department:\n");
	gets_s(ext_dept, 20);
		
	Inptbox.rcv_values(ext_title, ext_intercomNum, ext_dept);
	Inptbox.create_string();
	testing = Inptbox.validate();
	if (testing == true)
		return -1;
	else if (testing == false)
		Inptbox.write_string();

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
			std::cout << "You selected " << options << "\n ";
			std::cout << "Do you want to continue {Y/N)?: ";
			std::cin >> trigger;
			if (trigger == 'Y' || trigger == 'y') {
				RdWrt->printOut();
			}
			else if (trigger == 'N' || trigger == 'n') {
				std::cout << "Thank you. Good bye" << std::endl;
			}
			else { std::cout << trigger << " is not a valid entry. Exiting the application." << std::endl; }
		}
		else { std::cout << "Invalid entry. Ending the program." << std::endl; }

	return 0;
}
