#include<iostream>
#include<cstring>
#include "Nasir_Hussain_04072013040_A1.h"
int Employee::emp_no=0;
Employee::Employee():number(0)
{
	emp_no++;
	name="Default";
	designation="Default";
	salary=000000;
	emp_no=emp_no;
	get();
	
}
Employee::Employee(int n):number(n)
{
	emp_no++;
}

Employee Employee::set(int sal,char *n,char *deg)
{
	salary=sal;
	name = new char[strlen(n)+1];
	strcpy(name,n);
	designation=new char [strlen(deg)+1];
	strcpy(designation,deg);
	return *this;
}
int Employee::get_num() const
{
	return number;
}
void Employee::get() const
{
	get_num();
	cout<<emp_no<<"\t"
	<<get_num()<<"\t";
	cout<<name<<"\t"
	<<salary<<"\t"
	<<designation<<endl;
}
Employee::Employee(const Employee &obj):number(obj.number)//copy constructor
{
	name=new char[strlen(obj.name)+1];
	strcpy(name,obj.name);
	salary=obj.salary;
	designation=new char[strlen(obj.designation)+1];
	strcpy(designation,obj.designation);
}
Employee::~Employee()
{
    if(designation)
	{
	delete [] designation;	
	}
	else
	  NULL;
	if(name)
	 {
	  delete [] name;
	 }
    else
     NULL;
}
