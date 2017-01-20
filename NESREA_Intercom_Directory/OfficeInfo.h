#ifndef OFFICEINFO_H
#define OFFICEINFO_H

#include <fstream>
#include <iostream>
#include <string>

#include "PersonInfo.h"

typedef void INPUT;

#define MAX_STRINGLENGTH 50

class OfficeInfo :
	public PersonInfo
{
private:
	std::string _BUFFER;
	
	std::string _dept;
	std::string _intercomNum;

public:
	std::ifstream infile;
	//std::ofstream outfile;
	//std::fstream iofile;
	
	std::string searchTerm;
	
	
	OfficeInfo();
	~OfficeInfo();

	void setIntercomNum(std::string);
	void setDept(std::string);
	
	INPUT collectSearchTerm();
	void lookupTerm();

	void displayHeader() const;
	void show_ALL();
	void displayIndivRecord(std::string, int);
	//void showIntercomOnly() const;
	
	std::string capture_item(std::string &);
	


};
#endif // !OFFICEINFO_H