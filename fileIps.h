#ifndef FILEIPS_H_INCLUDED
#define FILEIPS_H_INCLUDED
#include "Record.h"
class fileIps:public Record {
    private:
        FILE * fPtrOut;
        char *new_string;
        int i, j;
    public:
        void set_members () {
                fPtrOut = fopen("office-contact.csv", "w");
                new_string = {};
                i = 0; j = 0;
                return;
            }
        fileIps() {
          set_members();
        }
        fileIps(const char * a, const char *b, const char *c) {
            Record::title = a; Record::intercomNum = b; Record::dept = c;
            set_members();
        }
        ~fileIps() {
            fclose(fPtrOut);
        };

        void create_string() {
            while ((new_string[i] = title[j]) != '\0');
            new_string[i] = ','; j = 0;
            while ((new_string[i] = intercomNum[j]) != '\0');
            new_string[i] = ','; j = 0;
            while ((new_string[i] = dept[j]) != '\0');
            new_string[i] = '\n';
            return;
        }

        void write_string() {

            fprintf(fPtrOut, new_string);
            return;
        }
};
#endif // FILEIPS_H_INCLUDED
