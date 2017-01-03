#include "PersonInfo.h"



PersonInfo::PersonInfo()
{
}


PersonInfo::~PersonInfo()
{
}

std::string PersonInfo::getCadreF()
{
	return cadre_full;
}

void PersonInfo::setCadreF(std::string cadre_f)
{
	cadre_full = cadre_f;
	return;
}

std::string PersonInfo::getCadreL()
{
	return cadre_long;
}

void PersonInfo::setCadreL(std::string cadre_l)
{
	cadre_long = cadre_l;
	return;
}

std::string PersonInfo::getCadreS()
{
	return cadre_short;
}

void PersonInfo::setCadre(std::string cadre_s)
{
	cadre_short = cadre_s;
	return;
}
