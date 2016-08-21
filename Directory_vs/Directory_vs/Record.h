/*
*	Copyright (c) 2016 Victor Ordu. All rights reserved.
*
*	The information and source code contained herein is the exclusive
*	property of Victor A. Ordu (victorordu@outlook.com) and may not be disclosed, examined
*	or reproduced in whole or in part without explicit written authorization
*	from the author.
*
*	PURPOSE:
*	A program for an application that will store and retrieve office contact details of staff
*	of the National Environmental Standards and Regulations Enforcement Agency (NESREA) HQ
*	at No. 4, Oro Ago Crescent, Garki II, Abuja, Nigeria.
*
*	Record.h
*/

#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
class Record {
protected:
	char title[30], intercomNum[4], dept[20];
public:
	// Constructors/deconstructor
	Record() {
		title[0] = {};
		intercomNum[0] = {};
		dept[0] = {};
	}
	~Record() { };
};
#endif // RECORD_H_INCLUDED