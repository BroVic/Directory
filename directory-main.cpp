#include<iostream>
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

int main() {
Office indiv;
indiv.printNum();

return 0;
}
