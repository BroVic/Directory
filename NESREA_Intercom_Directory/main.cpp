#include <iostream>
#include <fstream>
#include <string>
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
		case 3:
		case 4:
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

void showMainGreeting()
{
	std::cout << "NESREA HQ Intercom Directory" << std::endl;
	std::cout << "Copyright (C) Victor Ordu 2017. All Rights Reserved." << std::endl;
	std::cout.width(50);
	std::cout.fill('-');
	std::cout << '\n';
	return;
}

void showMainMenu()
{
	std::cout << "1 - Show All Records" << std::endl;
	std::cout << "2 - Search for a Record" << std::endl;
	std::cout << "3 - Add a New Record" << std::endl;
	std::cout << "4 - Update an Existing Record" << std::endl;
	return;
}
