#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
class Record {
protected:
	char *title;
	char *intercomNum;
	char *dept;
	// Constructors/deconstructor
public:
	Record();
	~Record() { };
};

Record::Record()
{
	title[0] = ' ';
	intercomNum[0] = ' ';
	dept[0] = ' ';
}
#endif // RECORD_H_INCLUDED
