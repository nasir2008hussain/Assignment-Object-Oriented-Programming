#include<iostream>
#include"Nasir_Hussain_04072013040_A1_def.h"
using namespace std;
int main()
{
    cout<<"S.No\tEmp_No\tEmp_Name\tSalary\tEmp_Rank"<<endl;
	cout<<"_________________________________________________"<<endl<<endl;
	cout<<"Calling Default Constructor & Getter"<<endl<<endl;
	Employee z;
	cout<<endl;
	cout<<"Calling Parametrized Constructor_&_Setter_&_Getter"<<endl<<endl;
	Employee a(809);
	a.set(900000,"Nasir Hussain","Professor");
	a.get();
	cout<<endl<<"Calling Copy Constructor "<<endl<<endl;
	Employee b(a);
    b.get();
	cout<<endl<<"Cascading Calls Possible"<<endl<<endl;
	Employee c(909);
	c.set(700000,"Shabbir Hasan","Assist Prof.").get();
	return 0;
}
