#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

/* Objects to be created:
1. File operations - fileOps
2. Representation of each record on file

*/
class Record{
	public:
		char title[30];
		char intercomNum[4];
		char dept[50];
	// Constructors/deconstructor
	Record(){
	    title[0] = ' ';
	    intercomNum[0] = ' ';
	    dept[0] = ' ';
	    return;
	}
	~Record(){return;}
};

class fileOps:public Record{
	protected:
		FILE *fptrIn;
		char stringIn[100];
		char b;
		int i, j, N;
	public:
		// constructors
		fileOps() {
			N = 1;
			b = ' ';
			stringIn[0] = {};
			fptrIn = fopen("office-contact.csv", "r");
			return;
		}
		~fileOps(){
			fclose(fptrIn);
			return;
		}

        // Pure virtual functions
		virtual void printOut() = 0;   // to print output
		virtual bool validate() = 0;   // to validate file opening

		// Functions for file operations
		void collectStrings(){          // for collecting strings from file
		fgets(stringIn, 99, fptrIn);
		return;
		}

		void splitString(){             // for splitting strings into parts
				int i = 0; int j = 0;
				while ((title[i++] = stringIn[j++]) != ',');
				for (; i < 29; i++) title[i-1] = ' ';
				title[i - 1] = '\0'; i = 0;
				while ((intercomNum[i++] = stringIn[j++]) != ',');
				intercomNum[i - 1] = '\0'; i = 0;
				while ((dept[i++] = stringIn[j++]) != '\0');
				return;
				}
};

class AllRecords:public fileOps {
	public:
		// Constructor/Deconstructor
		AllRecords() {return;}
		~AllRecords() {return;}

		virtual bool validate(){
		if (fptrIn == NULL){
				cout << "Could not open to print EXISTING records" << endl;
				return true;
				}
		else {return false;}
		}

		virtual void printOut(){            // for printing all existing records
			collectStrings();
			while(!feof(fptrIn)) {
				splitString();
				cout << N << b << title << b << intercomNum << b << dept << endl;
				collectStrings();
				N++;
			}
			cout << endl << endl;
			return;
		}
};

class SelectRecords:public fileOps {
	private:
		char str[];
		char inTitle[];
		int len;
	public:
		// Constructor/Deconstructor
		SelectRecords() {
		    str[0] = {};
			inTitle[0] = {};
			len = 0;
			return;
		}
		~SelectRecords() {return;}

		virtual bool validate(){
		if (fptrIn == NULL){
				cout << "Could not open to print SELECTED record(s)" << endl;
				return true;
				}
		else {return false;}
		}

		virtual void printOut() {           // for printing selected records
		    char tempIn[] = {}; char tempOut[] = {};
            cout << "Enter Officer's title: ";
            gets(str);
            len = strlen(str);
            for (int i = 0; i < len; i++) {
                    inTitle[i] = str[i];
            }
            collectStrings();
            while(!feof(fptrIn)) {
                splitString();
                for (i = 0;;i++){
                    tempIn[i] = inTitle[i];
                    tempOut[i] = title[i];
                }
                tempOut[j-1] = '\0';
                if (tempIn == tempOut) {
                    cout << N << b << title << b << intercomNum << b << dept << endl;
                }
                collectStrings();
                N++;
            }
        }
};

int main() {// constructors
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
