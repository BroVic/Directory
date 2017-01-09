#include "PersonInfo.h"



PersonInfo::PersonInfo()
{
}

PersonInfo::PersonInfo(
	std::string title, std::string fname, std::string lname, std::string cad_f, std::string cad_l, std::string cad_s) :
	_title (title), _firstName (fname), _lastName (lname), _cadre_full (cad_f), _cadre_long (cad_l), _cadre_short (cad_s)
{
}


PersonInfo::~PersonInfo()
{
}
void PersonInfo::set_title(std::string title)
{
	_title = title;
	return;
}

std::string PersonInfo::get_title() const
{
	return std::string(_title);
}

void PersonInfo::set_firstName(std::string fname)
{
	_firstName = fname;
	return;
}

std::string PersonInfo::get_firstName() const
{
	return std::string(_firstName);
}

void PersonInfo::set_lastName(std::string lname)
{
	_lastName = lname;
	return;
}

std::string PersonInfo::get_lastName() const
{
	return std::string(_lastName);
}

void PersonInfo::setCadreFull(std::string cad_f)
{
	_cadre_full = cad_f;
	return;
}

std::string PersonInfo::getCadreFull() const
{
	return std::string(_cadre_full);
}



std::string PersonInfo::getCadreLong() const
{
	return std::string(_cadre_long);
}

void PersonInfo::setCadreLong(std::string cad_l)
{
	_cadre_long = cad_l;
	return;
}

std::string PersonInfo::getCadreShort() const
{
	return std::string(_cadre_short);
}

void PersonInfo::setCadreShort(std::string cad_s)
{
	_cadre_short = cad_s;
	return;
}
