#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class Person{
protected:
string firstName, surname, title;
    long long int mobileNum;
public:
	Person() {                   // default constructor
	firstName = "Victor";
	surname = "Ordu";
	title = "Special Assistant";
	mobileNum = 2348034510441;
	return;
	}
	Person(string fn, string sn, string tt) {
	firstName = fn; surname = sn; title = tt;
	return;
	}

	~Person() {return;}
};
class Office:public Person {
protected:
    int roomNum, intercomNum;
public:
	Office() {
		roomNum = 203;
		intercomNum = 161;
		return;
	}
	Office(int rm, int ic) {
	roomNum = rm; intercomNum = ic;
	return;
	}
	~Office(){return;};
	void printNum() {
		cout << firstName  << " " << surname << "'s intercom No. is " << intercomNum << endl;
		return;
	}
};
class Department:public Office{
protected:
	string dept;
	int floorNum;
public:
	Department(){
		dept = "DG's Office";
		floorNum = 2;
		return;
	}
	Department(string de, int flo) {
	dept = de; floorNum = flo;
	return;
	}
	~Department(){return;}
};
class fileOps{
	FILE *fptrIn;
	char stringIn[100];
	char title[30], dept[50], intcom[4];
	char b;
	int i, k, N;
public:
	// constructors
	fileOps() {
		N = 1;
		b = ' ';
		fptrIn = fopen("office-contact.txt", "r"); // review this line!!!
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
		return false;
	}
	void printAll(){
		fgets(stringIn, 99, fptrIn);
		while(!feof(fptrIn)) {
			i = 0; k = 0;
			while ((title[i++] = stringIn[k++]) != ',');
			title[i - 1] = '\0'; i = 0;
			while ((intcom[i++] = stringIn[k++]) != ',');
			intcom[i - 1] = '\0'; i = 0;
			while ((dept[i++] = stringIn[k++]) != '\0');
			cout << N << b << title << b << intcom << b << dept << endl;
			fgets(stringIn, 99, fptrIn);
			N++;
		}
		cout << endl << endl;
		return;
	}
	};
int main() {
fileOps RdWrt;
Department indiv;

// Validation of success of file opening
bool testing{};
testing = RdWrt.validate();
if (testing == true) {return -1;}

// Look for a record

// Print out the result
RdWrt.printAll();
indiv.printNum();

// To input new data


return 0;
}
