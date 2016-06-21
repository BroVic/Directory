#include<iostream>
using namespace std;

class Department{
public:
	string dept;
	int floorNum;
};

class Office:public Department {
public:
    string title;
    int roomNum, intercomNum, 
};

class Person:public Department {
public:
	string name;
	long int mobileNum;
};

int main() {
Office A;
cout <<  "Who do you want to reach? " << endl;
cout << "Enter name: ";
cin >> A.name;

A.printNumber();

return 0;
}
