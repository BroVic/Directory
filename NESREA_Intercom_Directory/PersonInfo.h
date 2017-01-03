#pragma once
#include <string>
class PersonInfo
{
private:
	std::string title;
	std::string firstName;
	std::string lastName;
	std::string cadre_full;
	std::string cadre_long;
	std::string cadre_short;
	std::string alias;

public:
	PersonInfo();
	~PersonInfo();

	std::string getCadreF();
	void setCadreF(std::string);
	std::string getCadreL();
	void setCadreL(std::string);
	std::string getCadreS();
	void setCadre(std::string);
};

