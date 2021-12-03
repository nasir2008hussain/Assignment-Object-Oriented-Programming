#include<iostream>
#include<cstring>
using namespace std;
class String{
	private:
		char * strng;
	public:
	    String();
	    String(char *);
		void set_string( char *s);
		char *get_string() const;
		~String();
};
String::String(){
	strng="NULL";
}
String::String(char* s)
{
	strng=new char[strlen(s)+1];
	strcpy(strng,s);
}
void String::set_string(char *s)
{
	strng=new char[strlen(s)+1];
	strcpy(strng,s);
    
}
char *String::get_string() const
{

	return strng;
}
String::~String()
{

	delete[] strng;
}
