#ifndef CONTROLS_H
#define CONTROLS_H

#define MAIN_EXIT 0x0079

// A list of exit codes
enum ExitCode
{
	SUCCESS,
	INVALID_ENTRY,
};

// A list of main menu options
enum Menu
{
	DO_ALL = 1,
	DO_SEARCH,
	DO_INSERT,
	DO_UPDATE,
};

void showMainGreeting();
void showMainMenu();


#endif // !CONTROLS_H