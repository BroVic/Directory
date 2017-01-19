#ifndef OFFICEINFO_H
#define OFFICEINFO_H

// TODO: Define some constants/limits.

#include <fstream>
#include <iostream>
#include <string>

#include "PersonInfo.h"

class OfficeInfo :
	public PersonInfo
{
private:
	//std::string office;
	std::string _dept;
	std::string _intercomNum;
	std::string _BUFFER;
	OfficeInfo(std::string);

public:
	std::ifstream infile;
	//std::ofstream outfile;
	//std::fstream iofile;
	
	OfficeInfo();
	OfficeInfo(std::string, std::string);
	~OfficeInfo();

	void show_ALL();
	std::string capture_item(std::string &);

	void setIntercomNum(std::string);
	//void showIntercomOnly() const;

	void setDept(std::string);
};
#endif // !OFFICEINFO_H