#ifndef SELECTRECORDS_H_INCLUDED
#define SELECTRECORDS_H_INCLUDED
class SelectRecords :public fileOps {
private:
	char typed_string[30], tempStr[30];
	signed int comparison;
	int SN;
	size_t t;
public:
	// Constructor/Deconstructor
	SelectRecords() {
		typed_string[0] = {}; tempStr[0] = {};
		comparison = -1;
		SN = 1;
		t = 0;
	}
	~SelectRecords() { };

	virtual bool validate() {
		if (fptrIn == NULL) {
			std::cout << "Could not open to print SELECTED record(s)" << std::endl;
			return true;
		}
		else { return false; }
	}

	virtual void printOut() {
		// for printing selected records
		printf("Enter Officer's title: ");
		scanf("%29s", typed_string);
		// get the length of the entered string + NULL character

		collectStrings();
		while (!feof(fptrIn)) {
			// extract a string of equivalent length from the string on file
			for (t = 0; t < strlen(typed_string); t++) {
				tempStr[t] = file_string[t];
			}
			tempStr[t] = '\0';
			// compare both strings
			comparison = strcmp(tempStr, typed_string);
			// if identical, print out the string from file
			// else do nothing
			if (comparison == 0) {
				printf("%s \n", file_string);
			}
			collectStrings();
			SN++;
		}
	}
};
#endif // SELECTRECORDS_H_INCLUDED
