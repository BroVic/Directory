#include "OfficeInfo.h"
#include <cctype>
#include <iomanip>

OfficeInfo::OfficeInfo()
{
}

OfficeInfo::OfficeInfo(std::string dept, std::string intercom) :
	_dept (dept), _intercomNum (intercom)
{
	
}

OfficeInfo::~OfficeInfo()
{
}

// Displays all available records
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

		std::cout << std::setw(6) << std::left << "\nS/N";
		std::cout << std::setw(20) << std::left << "Title";
		std::cout << std::setw(7) << std::left << "Dial";
		std::cout << "Office/Dept" << std::endl;
		/*std::cout.width(45);
		std::cout.setf('-');
		std::cout << '\n';
		std::cout.width();
		std::cout.unsetf('-'); */
		std::cout << std::setw(45) << std::setfill('-') << '-';
		std::cout << std::setw(0)<<std::setfill(' ') << std::endl;

		int counter = 0;
		while (std::getline(infile, _BUFFER))
		{
			// process the string into its component parts
			if (!_BUFFER.empty())
			{
				setCadreLong(capture_item(_BUFFER));
				setIntercomNum(capture_item(_BUFFER));
				setDept(capture_item(_BUFFER));
				
				_BUFFER.clear();
				
				counter++;
				std::string title(getCadreLong());

				std::cout << std::setw(5) << std::left << counter;
				std::cout << std::setw(20) << std::left << title;
				std::cout << _intercomNum << "\t";
				std::cout << _dept << std::endl;
			}
			else
				break;
		}
	}
	else
	{
		std::cerr << "File office-contact.txt could not be opened" << std::endl;
		return;
	}
	
	infile.close();

	return;
}

// Extracts individual data fields from line in text file
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