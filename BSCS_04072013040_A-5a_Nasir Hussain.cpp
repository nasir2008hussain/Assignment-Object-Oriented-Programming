#include<iostream>
#include<cstring>
#include"Nasir_Hussain_date_class.h"
#include"Nasir_Hussain_string_class.h"
using namespace std;

class Employee{
	private:
		double tax;
		String name;
		Date date;
	public:
		Employee();
		Employee(int,int,int,double);
		void set_name(char *);
		char *get_name() const;
		int get_date() const;
		double get_tax() const;
		virtual void generate_slip();
		virtual double  Calculate_Salary()=0;
		virtual ~Employee();
		
};
Employee::Employee()
{
}
Employee::Employee(int dd,int mm,int yy,double t):date(dd,mm,yy)
{
	tax=t;
}
void Employee::set_name(char *n)
{
	name.set_string(n);
}
char *Employee::get_name() const
{
	return name.get_string();
}
int Employee::get_date() const
{
	date.get_Date();
}
void Employee::generate_slip()
{
	cout<<get_name()<<"\t";
	get_date();
}
double Employee::get_tax() const
{
	return tax;
}
Employee::~Employee(){
}
class Salaried_Emp:public Employee
{
	private:
		double salary;
		double net_salary;
	public:
		Salaried_Emp();
		Salaried_Emp(int d,int m,int y,double t,int sal);
		virtual double Calculate_Salary();
		virtual void generate_slip();
		virtual ~Salaried_Emp();
	
};
Salaried_Emp::Salaried_Emp()
{
}
Salaried_Emp::Salaried_Emp(int d,int m,int y,double t,int sal):Employee(d,m,y,t)
{
	salary=sal;
}
double Salaried_Emp::Calculate_Salary()
{
	net_salary=salary-((salary)*(get_tax()/100.0));
	return net_salary;
}
void Salaried_Emp::generate_slip()
{
	Employee::generate_slip();
	cout<<"Salaried_Emp\t"<<salary<<"\t";
	
}
Salaried_Emp::~Salaried_Emp(){
}

class Hourly_Emp:public Employee
{
	private:
		double hour;
		double hour_rate;
		double salary;
		double net_salary;
	public:
		Hourly_Emp();
		Hourly_Emp(int,int,int,double,double,double);
		virtual double Calculate_Salary();
		virtual void generate_slip();
		virtual ~Hourly_Emp();
};
Hourly_Emp::Hourly_Emp(){
}
Hourly_Emp::Hourly_Emp(int d,int m,int y,double t,double h,double hr):Employee(d,m,y,t)
{
	hour=h;
	hour_rate=hr;
	salary=hour * hour_rate;
}
double Hourly_Emp::Calculate_Salary()
{
	
    net_salary=salary-((salary)*(get_tax()/100.0));
	return net_salary;
}
void Hourly_Emp::generate_slip()
{
	Employee::generate_slip();
	cout<<"Hourly_Emp\t"<<salary<<"\t";
}
Hourly_Emp::~Hourly_Emp(){
}

class Commissioned_Emp:public Employee
{
	private:
		double sale;
		double com_rate;
		double salary;
		double net_salary;
	public:
		Commissioned_Emp();
		Commissioned_Emp(int,int,int,double,double,double);
		virtual void generate_slip();
		virtual double Calculate_Salary();
		virtual ~Commissioned_Emp();
	
};
Commissioned_Emp::Commissioned_Emp(){
}
Commissioned_Emp::Commissioned_Emp(int d,int m,int y,double t,double s,double cr):Employee(d,m,y,t)
{
	sale=s;
	com_rate=cr;
	salary=sale*(com_rate/100.0);
}
double Commissioned_Emp::Calculate_Salary()
{
	net_salary=salary-((salary)*(get_tax()/100.0));
	return net_salary;
	
}
void Commissioned_Emp::generate_slip()
{
	Employee::generate_slip();
	cout<<"Commissioned\t"<<salary<<"\t";
}
Commissioned_Emp::~Commissioned_Emp(){
}

void Generate_Report(Employee *emp[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<i+1<<".\t";
		emp[i]->generate_slip();
		cout<<emp[i]->Calculate_Salary()<<endl<<endl;
	}
	
}

int main()
{
	const int size=6;
	Employee* emp[size];
	Salaried_Emp e1(22,6,2021,2.5,20000);
	e1.set_name("Nasir Hussain");
	emp[0]=&e1;
	Hourly_Emp e2(14,12,2020,1.5,40,400);
	e2.set_name("Tahir Hussain");
	emp[1]=&e2;
	Commissioned_Emp e3(31,10,2020,2.6,160000,7);
	e3.set_name("Arif Hussain");
	emp[2]=&e3;
	Salaried_Emp e4(12,9,2020,4.5,60000);
	e4.set_name("Sajid Hussain");
	emp[3]=&e4;
	Hourly_Emp e5(24,11,2019,2.5,50,450);
	e5.set_name("Amir Hussain");
	emp[4]=&e5;
	Commissioned_Emp e6(11,11,2018,3.6,260000,8);
	e6.set_name("Talha Hussain");
	emp[5]=&e6;
	cout<<"S.No\tEmployee_Name\tJoining Date\tEmployee_Type\tSalary\tNet Salary"<<endl<<"__________________________________________________________________________\n";
	cout<<endl;
	Generate_Report(emp,size);
	cout<<"__________________________________________________________________________"<<endl<<endl;
	delete emp;
	system("pause");
}


