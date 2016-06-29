#include<iostream>
using namespace std;

class Person{
public:
    string firstName, surname, title;
    long long int mobileNum;
	Person() {
	firstName = "Victor";
	surname = "Ordu";
	title = "Special Assistant";
	mobileNum = 2348034510441;
	return;
	}
	~Person() {return;}
};

class Office:public Person {
    int roomNum, intercomNum;
public:
	Office() {
		roomNum = 203;
		intercomNum = 161;
		return;
	}
	~Office(){return;};
	void printNum() {
		cout << firstName  << " " << surname << "'s intercom No. is " << intercomNum << endl;
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
