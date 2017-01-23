#ifndef OFFICEINFO_H
#define OFFICEINFO_H

#include <fstream>
#include <iostream>
#include <string>
#include <array>

#include "PersonInfo.h"


typedef void INPUT;

#define MAX_STRINGLENGTH 20

class OfficeInfo :
	public PersonInfo
{
private:
	std::string _BUFFER;
	std::ifstream infile;
	std::ofstream outfile;

	std::string _dept;
	std::string _intercomNum;
	
public:
	//std::fstream iofile;
	std::string searchTerm;
	std::array<std::string, 3> input_call;
	std::array<std::string, 3> input_fields;
	size_t INSERTIONS;
	
	OfficeInfo();
	~OfficeInfo();

	void setIntercomNum(std::string);
	void setDept(std::string);
	
	std::string collectInput(std::string);
	INPUT collectSearchTerm();
	void lookupSearchTerm();

	void displayHeader() const;
	void show_ALL();
	void displayIndivRecord(std::string, int);
	//void showIntercomOnly() const;
	
	std::string capture_item(std::string &);

	void collateRecord();
	void writeNewRecord();
	
	// temporary method
	void tempInputMainData();

};
#endif // !OFFICEINFO_H