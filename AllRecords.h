#ifndef ALLRECORDS_H_INCLUDED
#define ALLRECORDS_H_INCLUDED
#include"fileOps.h"
class AllRecords:public fileOps {
	int SN;
	public:
		// Constructor/Deconstructor
		AllRecords() {SN = 1;}
		~AllRecords() { };

		virtual bool validate(){
		if (fptrIn == NULL) {
				std::cout << "Could not open to print EXISTING records" << std::endl;
				return true;
				}
		else {return false;}
		}

		virtual void printOut() {            // for printing all existing records
			collectStrings();
			while(!feof(fptrIn)) {
				splitString();
				std::cout << SN << brk << title << brk << intercomNum << brk << dept << std::endl;
				collectStrings();
				SN++;
			}
			std::cout << "\nEnd of print-out of available records.\n" << std::endl;
			return;
		}
};
#endif // ALLRECORDS_H_INCLUDED
