// functions.cpp
#include<iostream>
#include <iomanip>

void showMainGreeting()
{
	std::cout << "NESREA HQ Intercom Directory" << std::endl;
	std::cout << "Copyright (C) Victor Ordu 2017. All Rights Reserved." << std::endl;
	std::cout << std::setw(50) << std::setfill('-') << '\n';
	std::cout << std::setfill(' ');

	return;
}

void showMainMenu()
{
	std::cout << "\n1 - Show All Records" << std::endl;
	std::cout << "2 - Search for a Record" << std::endl;
	std::cout << "3 - Add a New Record" << std::endl;
	std::cout << "4 - Update an Existing Record" << std::endl;

	return;
}
