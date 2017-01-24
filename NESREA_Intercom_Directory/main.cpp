#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include "PersonInfo.h"
#include"OfficeInfo.h"

void showMainGreeting();

int main()
{
	showMainGreeting();
	char exit;
	
	OfficeInfo details;
	do
	{
		details.showMainMenu();

		int attempts{ }, selection{ };
		do
		{
			std::cin >> selection;
			if (attempts >= MAX_ATTEMPTS)
			{
				std::cerr << "You made 3 invalid entries. Goodbye." << std::endl;
				return INVALID_ENTRY;
			}

			if ((selection == DO_ALL) | (selection == DO_SEARCH) |
				(selection == DO_INSERT) | (selection == DO_UPDATE))
				break;
			else
			{
				std::cout << "Invalid entry" << std::endl;
				std::cout << "Try again: ";
				attempts++;
			}
		} while (true);

		switch (selection)
		{
		case DO_ALL:
			details.show_ALL();
			break;
		case DO_SEARCH:
			details.collectInput();
			details.lookupSearchTerm();
			break;
		case DO_INSERT:
			for (size_t i = 0; i < details.INSERTIONS; i++)
			{
				std::cout << "Enter Officer's " << details.input_call[i] << ": ";
				details.input_fields[i] = details.collectInput();
			}
			details.tempInputMainData();
			details.collateRecord();
			details.writeNewRecord();
			break;
		case DO_UPDATE:
			// TODO: call to update
			std::cout << "Yet to be implemented" << std::endl;
			break;
		default:
			return INVALID_ENTRY;
		}

		do
		{
			std::cin.ignore(32676, '\n');
			std::cout << "\nExit the program? (y/n) ";
			std::cin.get(exit);

			if (tolower(exit) == 0x006e)
				break;
			else if (tolower(exit) == 0x0079)
				return SUCCESS;
			else
			{
				exit = BLANK;
				continue;
			}
		} while (true);

		selection = -1;

	} while (tolower(exit) != MAIN_EXIT);

	return SUCCESS;
}

void showMainGreeting()
{
	std::cout << "NESREA HQ Intercom Directory" << std::endl;
	std::cout << "Copyright (C) Victor Ordu 2017. All Rights Reserved." << std::endl;
	std::cout << std::setw(50) << std::setfill('-') << '\n';
	std::cout << std::setfill(' ');

	return;
}
