#pragma once

enum ExitCode
{
	SUCCESS,
	INVALID_ENTRY,
};

enum Menu
{
	DO_ALL = 1,
	DO_SEARCH,
	DO_INSERT,
	DO_UPDATE,
};

void showMainGreeting();
void showMainMenu();