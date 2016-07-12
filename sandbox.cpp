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
		fptrIn = fopen("office-contact.csv", "r");
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
	// Function for extracting strings 
	void extractStr(Record &a, char &stringIn[]){
		int i = 0; int j = 0
			while ((a.title[i++] = stringIn[j++]) != ',');
			for (; i < 29; i++) a.title[i-1] = ' ';
			a.title[i - 1] = '\0'; i = 0;
			while ((a.intercomNum[i++] = stringIn[j++]) != ',');
			a.intercomNum[i - 1] = '\0'; i = 0;
			while ((a.dept[i++] = stringIn[j++]) != '\0');
			return;
	}
	// Function to print all available records to the console
	void printAll(Record &r){
		collectStrings();
		while(!feof(fptrIn)) {
			extractStr(r, stringIn);
			cout << N << b << r.title << b << r.intercomNum << b << r.dept << endl;
			collectStrings();
			N++;
		}
		cout << endl << endl;
		return;
	}
	/* Function to print only 1 record
	1. Declare 2 variables A & B
	2. Declare one array C
	3. Input a value A
	4. Collect a string from the file
	5. Extract from the string an appropriate value B that matches with A
	6. Compare A & B
	7. If A = B, then store item of interest in C
	8. If A != B, do nothing
	9. Repeat 4 - 9 until you reach end of the file
	10. Print elements of C one after the other
	11. End */
	
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
