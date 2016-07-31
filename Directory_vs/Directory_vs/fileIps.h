#ifndef FILEIPS_H_INCLUDED
#define FILEIPS_H_INCLUDED
class fileIps:public Record {
private:
	unsigned int i, j;
protected:
	FILE * fPtrOut;
	char new_string[44];  
public:
	fileIps();
    ~fileIps() { fclose(fPtrOut); }
	
	// function declarations
	bool validate();
	void rcv_values(char a[20], char b[4], char c[20]);
	void create_string();
	void write_string();
};

 fileIps::fileIps() {
	fopen_s(&fPtrOut, "example.txt", "a");
	if (feof(fPtrOut))
		printf("%s\n", "End-of-file condition!");
	new_string[0] = ' ';
	i = 0; j = 0;
}

 void fileIps::rcv_values(char a[20], char b[4], char c[20])
 {
	 for (i = 0; i < strlen(a); i++)
		 title[i] = a[i];
	 for (i = 0; i < strlen(b); i++)
		 intercomNum[i] = b[i];
	 for (i = 0; i < strlen(c); i++)
		 dept[i] = c[i];
 }

 bool fileIps::validate() {
	 if (fPtrOut == nullptr) {
		 std::cout << "Could not open the file" << std::endl;
		 return true;
	 }
	 else { return false; }
 }

 void fileIps::create_string()
 {
	i = 0;
	while ((new_string[i++] = title[j++]) != '\0');
	new_string[i - 1] = ','; j = 0;
	while ((new_string[i++] = intercomNum[j++]) != '\0');
	new_string[i - 1] = ','; j = 0;
	while ((new_string[i++] = dept[j++]) != '\0');
	new_string[i - 1] = '\n';
	return;
 }

 void fileIps::write_string() {
		 fwrite(&new_string, sizeof(new_string), 1, fPtrOut);
		 return;
 }

#endif // FILEIPS_H_INCLUDED
