#include "OfficeInfo.h"

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
	infile.open("office-contact.txt");
	if (infile.is_open())
	{
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
				std::cout << counter << "\t" << title << "\t" << _intercomNum << "\t" << _dept << std::endl;
			}
			else
				break;
		}
	}
	else
		std::cerr << "File office-contact.txt could not be opened" << std::endl;
	
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