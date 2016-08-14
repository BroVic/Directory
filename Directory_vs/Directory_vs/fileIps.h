#ifndef FILEIPS_H_INCLUDED
#define FILEIPS_H_INCLUDED
class fileIps:public Record {
private:
	unsigned int i, j;
protected:
	FILE * fPtrOut;
	std::string new_string;  
public:
	fileIps();
	fileIps(std::string, std::string, std::string);
	fileIps(std::string);
    ~fileIps() { fclose(fPtrOut); }
	
	// function declarations
	bool validate();
	void create_string();
	void write_string();
};

 fileIps::fileIps() {							// default constructor
	fopen_s(&fPtrOut, "example.txt", "a");
	if (feof(fPtrOut))
		printf("%s\n", "End-of-file condition!");
	new_string;
} 
 fileIps::fileIps(std::string str)					// copy constructor
 {
	 fopen_s(&fPtrOut, "example.txt", "a");
	 if (feof(fPtrOut))
		 printf("%s\n", "End-of-file condition");
	 new_string = str;
 }

 fileIps::fileIps(std::string a, std::string b, std::string c) // regular constructor
 {
	 fopen_s(&fPtrOut, "example.txt", "a");
	 if (feof(fPtrOut))
		 printf("%s\n", "End-of-file condition!");
	 new_string;
	 title = a;
	 intercomNum = b;
	 dept = c;
	 return;
 }
 // check wether file opening results in a null pointer
 bool fileIps::validate() {
	 if (fPtrOut == nullptr) {
		 std::cout << "Could not open the file" << std::endl;
		 return true;
	 }
	 else { return false; }
 }

 void fileIps::create_string()
 {
	 new_string = title;
	 new_string.append(",");
	 new_string.append(intercomNum);
	 new_string.append(",");
	 new_string.append(dept);
	 return;
 }

 void fileIps::write_string() {
		 fwrite(&new_string, sizeof(new_string), 1, fPtrOut);
		 return;
 }

#endif // FILEIPS_H_INCLUDED
