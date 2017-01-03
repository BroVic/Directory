#pragma once
#include "PersonInfo.h"
#include <iostream>
class OfficeInfo :
	public PersonInfo
{
private:
	std::string office;
	std::string dept;
	short intercomNum;
public:
	OfficeInfo();
	~OfficeInfo();

	void showIntercomNum();

};