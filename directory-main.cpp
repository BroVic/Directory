#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

/* Objects to be created:
1. File operations - fileOps
2. Representation of each record on file

*/

class Record{
	friend class fileOps;
	private:
		char title[30] = { 'D', 'G', '/', 'C', 'E', 'O', '\0' };
		char intercomNum[4] = {'1', '5', '0', '\0'};
		char dept[50] = {'D', 'G', '/', 'C', 'E', 'O', '\'', 's', 'O', 'f', 'f', 'i', 'c', 'e', '\0' };
	public:
	// Constructors/deconstructor
	Record(){
	return;
	}
	~Record(){return;}
};

class fileOps{
	FILE *fptrIn;
	char stringIn[100];
	char b;
	int i, j, N;
public:
	// constructors
	fileOps() {
		N = 1;
		b = ' ';
		fptrIn = fopen("office-contact.csv", "r"); // review this line!!!
		return;
	}
	~fileOps(){
		fclose(fptrIn);
		return;
	}
	bool validate(){
	if (fptrIn == NULL){
            cout << "Could not open database" << endl;
            return true;
            }
    else {return false;}
	}
	// Define a function for collecting record strings
	void collectStrings(){
	fgets(stringIn, 99, fptrIn);
	return;
	}
	// Function to print all available records to the console
	void printAll(Record &r){
		collectStrings();
		while(!feof(fptrIn)) {
			i = 0; j = 0;
			while ((r.title[i++] = stringIn[j++]) != ',');
			for (; i < 29; i++) r.title[i-1] = ' ';
			r.title[i - 1] = '\0'; i = 0;
			while ((r.intercomNum[i++] = stringIn[j++]) != ',');
			r.intercomNum[i - 1] = '\0'; i = 0;
			while ((r.dept[i++] = stringIn[j++]) != '\0');
			cout << N << b << r.title << b << r.intercomNum << b << r.dept << endl;
			collectStrings();
			N++;
		}
		cout << endl << endl;
		return;
	}
	// Function to print only 1 record
};

int main() {
Record row;
fileOps RdWrt;
int options = 0;
char trigger;
// Validation of success of file opening
bool testing{};
testing = RdWrt.validate();
if (testing == true){return -1;}
// Look for a record
// To print out all items in the database

cout << "To display available records, enter '1': ";
cin >> options;
cout << "You selected " << options << "\n ";
cout << "Do you want to continue {Y/N)?: ";
cin >> trigger;
if (trigger == 'Y' || trigger == 'y') {
	if (options == 1){
			RdWrt.printAll(row);
			}
	}
else if (trigger == 'N' || trigger == 'n'){
		cout << "Thank you. Good bye" << endl;
	}
else {cout << trigger << " is not a valid entry. Exiting the application." << endl;}
// Print out the result

return 0;
}
