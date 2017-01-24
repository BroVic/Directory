#ifndef PERSONINFO_H
#define PERSONINFO_H

#include <string>

#define	SUCCESS 0
#define	INVALID_ENTRY 1
#define	NO_ENTRY 2

#define MAIN_EXIT 0x0079
#define MAX_ATTEMPTS 3
#define MAX_STRINGLENGTH 20
#define BLANK ' '

#define DO_ALL  0x0001
#define DO_SEARCH 0x0002
#define DO_INSERT 0x0003
#define DO_UPDATE 0x0004

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
#endif // !PERSONINFO_H