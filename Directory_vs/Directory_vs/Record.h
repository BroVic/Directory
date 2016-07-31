#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
class Record {
protected:
	char title[20];
	char intercomNum[4];
	char dept[20];
	// Constructors/deconstructor
public:
	Record() {
		title[0] = ' ';
		intercomNum[0] = ' ';
		dept[0] = ' ';
	}
	~Record() { };
};
#endif // RECORD_H_INCLUDED