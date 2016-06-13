#include<iostream>
using namespace std;

class Office {
private:
    string name;
    char title[];
    int roomNumber, intercom;
public:
    Office(){
        name {}; title{}; roomNumber = intercom = 0;
    }                       // constructors
    ~Office()
    void printNumber() {
    cout << "The intercom number of " << name << " is: ";
    cout << intercom << endl;
    return;
    }
};

int main() {
Office A;
cout <<  "Who do you want to reach? " << endl;
cout << "Enter name: ";
cin >> A.name;

A.printNumber();

return 0;
}
