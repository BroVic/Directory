#include <iostream>
#include <fstream>
#include <string>
#include "PersonInfo.h"
#include"OfficeInfo.h"

int main()
{
	OfficeInfo details;
	details.show_ALL();
	
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