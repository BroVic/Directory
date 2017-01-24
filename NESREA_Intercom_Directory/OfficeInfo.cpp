#include "OfficeInfo.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <array>

OfficeInfo::OfficeInfo()
{
	input_call = { "Cadre", "Intercom No.", "Department" };
	INSERTIONS = input_call.size();
}

OfficeInfo::~OfficeInfo()
{
}

 void OfficeInfo::setIntercomNum(std::string num)
{
	_intercomNum = num;
	return;
}

/*
void OfficeInfo::showIntercomOnly()
{
	std::cout << "Intercom No.: " << intercomNum << std::endl;
	return;
}
*/

void OfficeInfo::setDept(std::string off)
{
	_dept = off;
	return;
}

void OfficeInfo::showMainMenu() const
{
	std::cout << "\nCHOOSE AN OPTION: " << std::endl;
	std::cout << "1 - Show All Records" << std::endl;
	std::cout << "2 - Search for a Record" << std::endl;
	std::cout << "3 - Add a New Record" << std::endl;
	std::cout << "4 - Update an Existing Record" << std::endl;
	std::cout << "--> ";

	return;
}


std::string OfficeInfo::collectInput()
{
	std::cin.clear();
	std::cin.ignore(32676, '\n');
	std::cout << "Supply a term: ";
	std::getline(std::cin, searchTerm);
	
	while (true)
	{
		if (searchTerm.length() == 0)
		{
			std::cout << "No entry made." << std::endl << std::endl;
		}
		else
		{
			std::cout << '\n';
			break;
		}
		std::cout << "Try again: ";
		collectInput();			// review this!!!
	}
	return searchTerm;
}
/*
void OfficeInfo::collectSearchTerm()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "Enter your search term: ";
	searchTerm = collectInput(input);
	return;
}
*/

void OfficeInfo::lookupSearchTerm()
{
	infile.open("office-contact.txt");
	
	if (infile.is_open())
	{
		displayHeader();

		int counter = 0;
		while (std::getline(infile, _BUFFER))
		{
			if (_BUFFER.find(searchTerm) != _BUFFER.npos)
				displayIndivRecord(_BUFFER, counter);
			if (infile.eof())
				break;
		}
	}
	else
	{
		std::cerr << "Could not open data source." << std::endl;
	}

	infile.close();
	
	return;
}

void OfficeInfo::show_ALL()
{
	bool run;
	do
	{
		char opt;
		std::cout << "\nDisplay all avaiable records(Y/N)?: ";
		std::cin >> opt;
		if (tolower(opt) == (char)0x79)
		{
			run = true;
			break;
		}
		else if (tolower(opt) == (char)0x6e)
		{
			run = false;
			break;
		}
	} while (true);
	
	if (!run)
	{
		std::cout << "Returning to main menu." << std::endl
			<< std::endl;
		return;
	}

	infile.open("office-contact.txt");
	if (infile.is_open())
	{
		std::cout << "Showing all records: " << std::endl;
		displayHeader();

		int counter = 0;
		while (std::getline(infile, _BUFFER))
			displayIndivRecord(_BUFFER, counter);
	}
	else
	{
		std::cerr << "File office-contact.txt could not be opened" << std::endl;
		return;
	}
	
	infile.close();

	return;
}

void OfficeInfo::displayHeader() const
{
	std::cout << std::setw(6) << std::left << "\nS/N";
	std::cout << std::setw(20) << std::left << "Title";
	std::cout << std::setw(7) << std::left << "Dial";
	std::cout << "Office/Dept" << std::endl;
	std::cout << std::setw(45) << std::setfill('-') << '-';
	std::cout << std::setw(0) << std::setfill(' ') << std::endl;

	return;
}

std::string OfficeInfo::capture_item(std::string & buff)
{
	std::string temp;
	size_t len = buff.length();

	unsigned int i = 0;
	while (i < len)
	{
		if ((buff[i] == ','))
			break;
		else
		{
			temp.push_back(buff[i]);
			i++;
		}
	}
	buff.erase(0, ++i);

	return temp;
}

void OfficeInfo::collateRecord()
{
	_BUFFER.clear();
	_BUFFER = get_title();
	_BUFFER.append(",");
	_BUFFER.append(_intercomNum);
	_BUFFER.append(",");
	_BUFFER.append(_dept);

	return;
}

void OfficeInfo::writeNewRecord()
{
	outfile.open("office-contact.txt", std::ios_base::app);

	if (outfile.is_open())
	{
		int count = 0;
		std::cout << "Confirm your entry: " << std::endl;
		displayHeader();
		displayIndivRecord(_BUFFER, count);

		char decide;
		std::cout << "Save to file? (y/n) ";
		std::cin >> decide;
		if (tolower(decide) == 'y')
			outfile << _BUFFER << std::endl;
		else if (tolower(decide) == 'n')
			std::cout << "You declined to proceed with making entry." << std::endl;
		else
			std::cout << "Invalid entry." << std::endl;
	}
	else
		std::cerr << "Could not open the data file." << std::endl;

	outfile.close();

	return;
}

void OfficeInfo::tempInputMainData()
{
	set_title(input_fields[0]);
	_intercomNum = input_fields[1];
	_dept = input_fields[2];
	return;
}

void OfficeInfo::displayIndivRecord(std::string buff, int it)
{
	// process the string into its component parts
	if (!buff.empty())
	{
		setCadreLong(capture_item(buff));
		setIntercomNum(capture_item(buff));
		setDept(capture_item(buff));

		buff.clear();

		it++;
		std::string title(getCadreLong());

		std::cout << std::setw(5) << std::left << it;
		std::cout << std::setw(20) << std::left << title;
		std::cout << _intercomNum << "\t";
		std::cout << _dept << std::endl;
	}
	return;
}