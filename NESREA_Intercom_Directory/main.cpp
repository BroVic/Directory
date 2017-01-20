#include <iostream>
#include <fstream>
#include "PersonInfo.h"
#include"OfficeInfo.h"
#include "Controls.h"

int main()
{
	showMainGreeting();
	char exit = 0x006e;
	
	do
	{
		showMainMenu();

		int attempts{ 0 };
		int select{};
		do
		{
				
			std::cin >> select;

			attempts++;

			if (attempts > 3)
			{
				std::cerr << "You made 3 invalid entries. Goodbye." << std::endl;
				return INVALID_ENTRY;
			}
		} while ((select < 1) | (select > 4));

		OfficeInfo details;
		switch (select)
		{
		case DO_ALL:
			details.show_ALL();
			break;
		case DO_SEARCH:
			std::cout << "Enter your search term: ";
			details.collectSearchTerm();
			details.lookupTerm();
			break;
		case DO_INSERT:
			// TODO: call to insert
		case DO_UPDATE:
			// TODO: call to update
			std::cout << "Yet to be implemented" << std::endl;
			break;
		default:
			break;
		}

		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "\nExit the program? (y/n) ";
		std::cin.get(exit);

	} while (tolower(exit) != MAIN_EXIT);

	return SUCCESS;
}