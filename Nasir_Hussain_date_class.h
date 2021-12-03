#include<iostream>
using namespace std;
class Date
{
	private:
		int day;
		int month;
		int year;
	public:
		Date();
	    Date(int ,int , int );
	    int get_Date() const;
	    ~Date();
};
Date::Date(){
	day=0;
	month=0;
	year=0;
}
Date::Date(int d,int m,int y)
{
	day=d;
	month=m;
	year=y;
}
int Date::get_Date() const
{

	cout<<day<<"/"<<month<<"/"<<year<<"\t";
}
Date::~Date(){
}
