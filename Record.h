#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
class Record {
	protected:
		char title[30];
		char intercomNum[4];
		char dept[50];
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
