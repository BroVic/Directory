#include<iostream>
using namespace std;

class Department{
protected:
	string dept;
	int floorNum;
public:
	Department("DG's Office", 2);
	~Department();
};

class Office:public Department {
public:
    string title;
    int roomNum, intercomNum;
	Office("Special Assistant", 203, 161);
	~Office();
};

class Person:public Department {
public:
	string firstName, surname;
	long int mobileNum;
	Person("Victor", "Ordu", 2348034510441);
	~Person();
	
};

int main() {
;
cout <<  "Who do you want to reach? " << endl;
cout << "Enter name: ";
cin >> A.name;

A.printNumber();

return 0;
}
