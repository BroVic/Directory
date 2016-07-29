#ifndef FILEIPS_H_INCLUDED
#define FILEIPS_H_INCLUDED
#include<cstdio>
#include "Record.h"
class fileIps:public Record {
        FILE * fPtrOut;
        char new_string[85];
        int i, j;
public:
	fileIps();
    ~fileIps() { fclose(fPtrOut); }
	
	void enter_values(char *a, char *b, char *c);
	void create_string();
	void write_string();
};

 fileIps::fileIps() {
	fPtrOut = fopen("office-contact.csv", "w");
	new_string[0] = {};
	i = 0; j = 0;
}

 void fileIps::enter_values(char *a, char *b, char *c)
 {
	 printf("%s", "Enter Officer's Title:\n");
	 fgets(a, 40, stdin);
	 printf("%s", "Enter Officer's Intercom Number:\n");
	 fgets(b, 5, stdin);
	 printf("%s", "Enter Officer's Department:\n");
	 fgets(c, 40, stdin);
	 return;
 }

 void fileIps::create_string()
 {
	 while (!feof(fPtrOut))
	 {
		 int i = 0; int j = 0;
		 while ((new_string[i++] = title[j++]) != '\n');
		 new_string[i - 1] = ','; j = 0;
		 while ((new_string[i++] = intercomNum[j++]) != '\n');
		 new_string[i - 1] = ','; j = 0;
		 while ((new_string[i++] = dept[j++]) != '\n');
		 new_string[i - 1] = '\0';
	 }
	 return;
 }

 void fileIps::write_string() {
	 fprintf(fPtrOut, "%s", new_string);
	 return;
 }

#endif // FILEIPS_H_INCLUDED
