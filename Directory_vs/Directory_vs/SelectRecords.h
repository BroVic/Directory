#ifndef SELECTRECORDS_H_INCLUDED
#define SELECTRECORDS_H_INCLUDED
class SelectRecords :public fileOps {
private:
	std::string typed_string, tempStr;
	signed int comparison;
	int SN;
	size_t t;
public:
	// Constructor/Deconstructor
	SelectRecords() {
		typed_string;
		tempStr;
		comparison = -1;
		SN = 1;
		t = 0;
	}
	~SelectRecords() { };

	virtual bool validate();  // to check whether memmore was allocated successfully
	virtual void printOut();  // to print out the selected records
};
#endif // SELECTRECORDS_H_INCLUDED

// Function definitions
bool SelectRecords::validate() {
	if (fptrIn == nullptr) {
		std::cout << "Could not open to print SELECTED record(s)" << std::endl;
		return true;
	}
	else { return false; }
}

void SelectRecords::printOut() {
	// for printing selected records
	printf("Enter Officer's title: ");
	gets_s(typed_string, 29);
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