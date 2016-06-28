#include<iostream>
using namespace std;

class Person{
public:
    string firstName, surname;
    long long int mobileNum;
	Person() {
	firstName = "Victor";
	surname = "Ordu";
	mobileNum = 2348034510441;
	return;
	}
	~Person() {return;}
};

class Office:public Person {
    string title;
    int roomNum, intercomNum;
public:
	Office() {
		title = "Special Assistant";
		roomNum = 203;
		intercomNum = 161;
		return;
	}
	~Office(){return;};
	void printNum() {
		cout <<  "Intercom No. of " << firstName << " " << surname << " is " << intercomNum << endl;
		return;
	}
};
class Department:public Office{
	string dept;
	int floorNum;
public:
	Department(){
		dept = "DG's Office";
		floorNum = 2;
		return;
	}
	~Department(){return;}
};

int main() {
Office indiv;
indiv.printNum();

return 0;
}
