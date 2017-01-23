#include <iostream>
#include <fstream>
#include "PersonInfo.h"
#include"OfficeInfo.h"
#include "Controls.h"

int main()
{
	showMainGreeting();
	char exit = 0x0020;
	
	do
	{
		showMainMenu();

		int attempts{ 0 };
		int selection{};
		do
		{
			std::cin >> selection;
			attempts++;
			if (attempts > 3)
			{
				std::cerr << "You made 3 invalid entries. Goodbye." << std::endl;
				return INVALID_ENTRY;
			}
		} while ((selection < 1) | (selection > 4));

		OfficeInfo details;
		std::string str;
		switch (selection)
		{
		case DO_ALL:
			details.show_ALL();
			break;
		case DO_SEARCH:
			details.collectSearchTerm();
			details.lookupSearchTerm();
			break;
		case DO_INSERT:
			for (size_t i = 0; i < details.INSERTIONS; i++)
			{
				std::cout << "Enter Officer's " << details.input_call[i] << ": ";
				details.input_fields[i] = details.collectInput(str);
			}
			details.tempInputMainData();
			/*
			details.setCadreLong();
			details.setIntercomNum(icom);
			details.setDept(off);
			*/
			details.collateRecord();
			details.writeNewRecord();
			break;
		case DO_UPDATE:
			// TODO: call to update
			std::cout << "Yet to be implemented" << std::endl;
			break;
		default:
			break;
		}

		do
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nExit the program? (y/n) ";
			std::cin.get(exit);
		} while ((tolower(exit) != 0x006e) | (tolower(exit) != 0x0079));

	} while (tolower(exit) != MAIN_EXIT);

	return SUCCESS;
}