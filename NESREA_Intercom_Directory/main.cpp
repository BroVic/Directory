#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "PersonInfo.h"
#include"OfficeInfo.h"

void showMainGreeting();
void showMainMenu();


int main()
{
	showMainGreeting();

	showMainMenu();

	char POW{ ' ' };
	while (POW != 'Q')
	{
		int attempts{ 0 };
		int select{ -1 };
		do
		{
			
			std::cout << "\nCHOOSE AN OPTION: ";
			std::cin >> select;
			attempts++;

			if (attempts > 3)
			{
				std::cerr << "You nade 3 invalid entries. Goodbye." << std::endl;
				return 1;
			}
		} while (select < 1 | select > 4);

		OfficeInfo details;
		switch (select)
		{
		case 1:
			details.show_ALL();
			break;
		case 2:
			// TODO:  call for search
		case 3:
			// TODO: call to insert
		case 4:
			// TODO: call to update
			std::cout << "Yet to be implemented" << std::endl;
			break;
		default:
			break;
		}
	}
	
	/*
	std::ifstream testforfile;
	testforfile.open("office-contact.txt");
	if (testforfile.is_open())
	{
		std::cout << "File is open" << std::endl;
	}
	else
	{
		std::cout << "File could not open" << std::endl;
	}
	*/

	std::cin.get();

	return 0;
}