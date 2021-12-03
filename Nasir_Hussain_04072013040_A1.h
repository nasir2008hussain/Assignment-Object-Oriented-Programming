#include<iostream>
#include<cstring>
using namespace std;
class Employee{
	private:
		int const number;
		char *name;
		int salary;
		char *designation;
		static int emp_no;
	public:
		Employee();
        Employee(int n);
	    Employee(const Employee &obj);//copy constructor
        Employee set(int sal, char *n,char *deg);
		int get_num() const;//read only function->constant
	    void get() const;//read only function
	    ~Employee();	
};


