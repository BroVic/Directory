#pragma once


#include <string>

class PersonInfo
{
private:
	std::string _title;
	std::string _firstName;
	std::string _lastName;
	std::string _cadre_full;
	std::string _cadre_long;
	std::string _cadre_short;
	std::string alias;

public:
	PersonInfo();
	PersonInfo(
		std::string, std::string, std::string, std::string, std::string, std::string);
	~PersonInfo();

	void set_title(std::string);
	std::string get_title() const;

	void set_firstName(std::string);
	std::string get_firstName() const;

	void set_lastName(std::string);
	std::string get_lastName() const;

	void setCadreFull(std::string);
	std::string getCadreFull() const;

	std::string getCadreLong() const;
	void setCadreLong(std::string);

	std::string getCadreShort() const;
	void setCadreShort(std::string);
};

