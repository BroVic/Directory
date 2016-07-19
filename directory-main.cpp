#include<iostream>
#include<cstring>
#include<cstdio>
#include"Record.h"
#include"fileOps.h"
#include"AllRecords.h"
#include"SelectRecords.h"

int main() {
	fileOps *RdWrt;
	// AllRecords all;
	SelectRecords some;
	// char trigger;
	// int options;
	bool testing{};

	// Validation of file opening


	// Look for selected records
	RdWrt = &some;

	testing = RdWrt->validate();
	if (testing == true){return -1;}

	RdWrt->printOut();

	/* To print out all items in the database
	RdWrt = &all;
	testing = RdWrt->validate();
	if (testing == true){return -1;}
	cout << "To display available records, enter '1': ";
	cin >> options;
	cout << "You selected " << options << "\n ";
	cout << "Do you want to continue {Y/N)?: ";
	cin >> trigger;
	if (trigger == 'Y' || trigger == 'y') {
		if (options == 1){
				RdWrt->printOut();
		}
	}
	else if (trigger == 'N' || trigger == 'n'){
			cout << "Thank you. Good bye" << endl;
	}
	else {cout << trigger << " is not a valid entry. Exiting the application." << endl;}
	*/
return 0;
}
