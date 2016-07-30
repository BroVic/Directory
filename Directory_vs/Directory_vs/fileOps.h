#ifndef FILEOPS_H_INCLUDED
#define FILEOPS_H_INCLUDED
#include"Record.h"
class fileOps :public Record {
private:
	int i, j;  // counters
protected:
	FILE *fptrIn;
	char file_string[100];  // to be changed to pointer instead
public:
	fileOps() {
		fptrIn = fopen("office-contact.csv", "r");
		file_string[0] = {};
		i = 0; j = 0;
	}
	~fileOps() { fclose(fptrIn); }

	// Pure virtual functions to be implemented in derived classes
	virtual void printOut() = 0;   // to print output
	virtual bool validate() = 0;   // to validate file opening

								   // Functions for file operations
	void collectStrings() {          // for collecting strings from file
		fgets(file_string, 99, fptrIn);
		return;
	}

	void splitString() {             // for splitting strings into parts
		i = 0; j = 0;
		while ((title[i++] = file_string[j++]) != ',');
		for (; i < 29; i++) title[i - 1] = ' ';
		title[i - 1] = '\0'; i = 0;
		while ((intercomNum[i++] = file_string[j++]) != ',');
		intercomNum[i - 1] = '\0'; i = 0;
		while ((dept[i++] = file_string[j++]) != '\0');
		return;
	}
};
#endif // FILEOPS_H_INCLUDED
