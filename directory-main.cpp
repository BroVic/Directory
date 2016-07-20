#include<iostream>
#include<cstring>
#include<cstdio>
#include"AllRecords.h"
#include"SelectRecords.h"
int main() {
	fileOps *RdWrt;
	AllRecords all;
	SelectRecords some;
	char trigger{};
	int options = 0;
	bool testing{};

    // Input instructions and conditionals
	std::cout << "To print selected records, type 1." << std::endl;
	std::cout << "To print all records, type 2." << std::endl;
	std::cout << "Selection: ";
	std::cin >> options;
	if (options == 1) {
        // Look for selected records
        RdWrt = &some;
        testing = RdWrt->validate();
        if (testing == true){return -1;}
        RdWrt->printOut();
	}
	else if (options == 2) {
        // To print out all items in the database
        RdWrt = &all;
        testing = RdWrt->validate();
        if (testing == true){return -1;}
        std::cout << "You selected " << options << "\n ";
        std::cout << "Do you want to continue {Y/N)?: ";
        std::cin >> trigger;
        if (trigger == 'Y' || trigger == 'y') {
            RdWrt->printOut();
        }
        else if (trigger == 'N' || trigger == 'n'){
                std::cout << "Thank you. Good bye" << std::endl;
        }
        else {std::cout << trigger << " is not a valid entry. Exiting the application." << std::endl;}
        }
	else {std::cout << "Invalid entry. Ending the program." << std::endl;}

return 0;
}
