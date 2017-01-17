#include <iostream>
#include <fstream>
#include "PersonInfo.h"
#include"OfficeInfo.h"
#include "Controls.h"




int main()
{
	showMainGreeting();

	showMainMenu();

	char POW{ ' ' };
	while (POW != 'Q')
	{
		int attempts{ 0 };
		int select{  };
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
		} while ((select < 1) | (select > 4));

		OfficeInfo details;
		switch (select)
		{
		case DO_ALL:
			details.show_ALL();
			break;
		case DO_SEARCH:
			// TODO:  call for search
		case DO_INSERT:
			// TODO: call to insert
		case DO_UPDATE:
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