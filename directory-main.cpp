#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

/* Objects to be created:
1. File operations - fileOps
2. Representation of each record on file

*/
class Record {
	public:
		char title[30];
		char intercomNum[4];
		char dept[50];
	// Constructors/deconstructor
	Record() {
	    title[0] = ' ';
	    intercomNum[0] = ' ';
	    dept[0] = ' ';
	}
	~Record() { };
};

class fileOps:public Record {
	protected:
		FILE *fptrIn;
		char file_string[100];
		int i, j;
		char brk;
	public:
		// constructors
		fileOps() {
			fptrIn = fopen("office-contact.csv", "r");
			file_string[0] = {};
			i = 0; j = 0;
			brk = ' ';
		}
		~fileOps() {fclose(fptrIn);}

        // Pure virtual functions
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
				for (; i < 29; i++) title[i-1] = ' ';
				title[i - 1] = '\0'; i = 0;
				while ((intercomNum[i++] = file_string[j++]) != ',');
				intercomNum[i - 1] = '\0'; i = 0;
				while ((dept[i++] = file_string[j++]) != '\0');
				return;
				}
};

class AllRecords:public fileOps {
	int SN;
	public:
		// Constructor/Deconstructor
		AllRecords() {SN = 1;}
		~AllRecords() { };

		virtual bool validate(){
		if (fptrIn == NULL) {
				cout << "Could not open to print EXISTING records" << endl;
				return true;
				}
		else {return false;}
		}

		virtual void printOut() {            // for printing all existing records
			collectStrings();
			while(!feof(fptrIn)) {
				splitString();
				cout << SN << brk << title << brk << intercomNum << brk << dept << endl;
				collectStrings();
				SN++;
			}
			cout << "\nEnd of print-out of available records.\n" << endl;
			return;
		}
};

class SelectRecords:public fileOps {
	private:
		char typed_string[30], tempStr[30];
		signed int comparison;
		int SN;
	public:
		// Constructor/Deconstructor
		SelectRecords() {
		    typed_string[0] = {}; tempStr[0] = {};
		    comparison = -1;
		    SN = 1;
		}
		~SelectRecords() { };

		virtual bool validate(){
		if (fptrIn == NULL){
				cout << "Could not open to print SELECTED record(s)" << endl;
				return true;
				}
		else {return false;}
		}

		virtual void printOut() {
			 // for printing selected records
            printf("Enter Officer's title: ");
            scanf("%29s", typed_string);
            // get the length of the entered string + NULL character

            collectStrings();
            while(!feof(fptrIn)) {
            	// extract a string of equivalent length from the string on file
                for (i = 0; i < strlen(typed_string); i++) {
					tempStr[i] = file_string[i];
                }
                tempStr[i] = '\0';
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

int main() {
	fileOps *RdWrt;
	// AllRecords all;
	SelectRecords some;
	// char trigger;
	// int options;
	bool testing{};

	// Validation of file opening


	// Look for selected records
	RdWrt = &some;

	testing = RdWrt->validate();
	if (testing == true){return -1;}

	RdWrt->printOut();

	/* To print out all items in the database
	RdWrt = &all;
	testing = RdWrt->validate();
	if (testing == true){return -1;}
	cout << "To display available records, enter '1': ";
	cin >> options;
	cout << "You selected " << options << "\n ";
	cout << "Do you want to continue {Y/N)?: ";
	cin >> trigger;
	if (trigger == 'Y' || trigger == 'y') {
		if (options == 1){
				RdWrt->printOut();
		}
	}
	else if (trigger == 'N' || trigger == 'n'){
			cout << "Thank you. Good bye" << endl;
	}
	else {cout << trigger << " is not a valid entry. Exiting the application." << endl;}
	*/
return 0;
}
