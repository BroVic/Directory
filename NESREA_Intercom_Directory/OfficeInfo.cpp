#include "OfficeInfo.h"
#include <cctype>
#include <iomanip>

OfficeInfo::OfficeInfo()
{
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

void OfficeInfo::collectSearchTerm()
{
	char entry[MAX_STRINGLENGTH];

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get(entry, MAX_STRINGLENGTH);
	
	searchTerm = entry;
	while (true)
	{
		if (searchTerm.length() > MAX_STRINGLENGTH)
			std::cout << "Maximum allowed is 50 characters" << std::endl << std::endl;
		else if (searchTerm.length() == 0)
			std::cout << "No entry made." << std::endl << std::endl;
		else
		{
			std::cout << '\n';
			break;
		}
		std::cout << "Try again: ";
		collectSearchTerm();
	}	
	return;
}

void OfficeInfo::lookupTerm()
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