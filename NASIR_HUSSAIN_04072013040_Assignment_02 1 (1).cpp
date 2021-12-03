#include<iostream>
#include<cstring>
using namespace std;
class Array
{
	private:
		const int size;
		float local_avg;
		static int global_count;
		static int global_size;
		static float global_average;
	    int *ptr;
	public:
	  Array():size(0){
	  }
	  Array(int arr[],int s);
	  float get_local_avg();
	  static int get_global_count();
	  static int get_global_size();
	  static float get_global_average();
	  Array & operator +(const Array & a2);
	  Array & operator -(const Array & a2);
	  Array & operator ++(int);
	  Array & operator --(int);
	 friend ostream & operator <<(ostream & os, const Array &c)
	 {
	   for(int i=0;i<c.size;i++)
	   {
	  	 os<<c.ptr[i]<<" ";
	   }
		return os;
		} 
	 friend istream & operator >>(istream & is, const Array &c)
	   {
	  	 int i;
         if(i<c.size)
		 {
			is>>c.ptr[i];
		 }  
		}
		Array & operator ()(int index,int end);
	    int &operator[](int);
		~Array();
	  	
};

int Array :: global_count=0;
int Array :: global_size=0;
float Array :: global_average=0.0;

 Array::Array(int arr[],int s):size(s)
{
	global_count++;
	ptr=new int[s];
	for(int i=0;i<size;i++)
	{
	  ptr[i]= arr[i];
	  global_size++;
	}
}
float Array:: get_local_avg()
{
	local_avg=0;
	for(int i=0;i<size;i++)
	{
	  local_avg=local_avg+ptr[i];
    }
    global_average=global_average+local_avg;
	local_avg=local_avg/size;
	
	return local_avg;
}
int Array::get_global_count()
    {
	  return global_count;
	}	
int Array:: get_global_size()
    {
		return global_size;
	}	 
float Array::get_global_average()
    {
      global_average=global_average/global_size;
	  return global_average;
	}	 
Array & Array:: operator +(const Array & a2)
    {
	   cout<<"SUM OF TWO ARRAY : ";
        if(size==a2.size)
		{
			for(int i=0;i<size;i++){
				cout<<ptr[i]+a2.ptr[i]<<" ";
		}
		cout<<endl;
		}
	    else
	     cout<<"size not match"<<endl;
	}	
Array & Array :: operator -(const Array & a2)
   {
	 cout<<"SUBSTRACTION OF TWO ARRAY : ";
     if(size==a2.size)
	 {
		for(int i=0;i<size;i++){
			cout<<ptr[i]-a2.ptr[i]<<" ";
		}
		cout<<endl;
		}
	    else
	     cout<<"size not match"<<endl;
	}	  
Array & Array :: operator ++(int)
   {
	  for(int i=0;i<size;i++)
	  {
	   cout<<ptr[i]+1<<" ";
	  }
	  cout<<endl;
	} 
Array & Array :: operator --(int)
   {
	  int arr[size];
	  for(int i=0;i<size;i++)
	  {
	   cout<<ptr[i]-1<<" ";
	   }
	   cout<<endl;
	} 
Array & Array :: operator ()(int index,int end)
	{
  	int *p=new int[end+1];
	 if(index>0 && index<=size && end>0 && end<=size)
		{
		 cout<<"("<<index<<","<<end<<") : ";
		 for(int i=index;i<=end;i=++index)
			{
		  	  p[i]=ptr[index-1];
		  	  cout<<p[i]<<" ";
			}
			cout<<endl;
		}
	    else
			cout<<"("<<index<<","<<end<<") can't show"<<endl; 
	    delete []p;
	}		  		  	        
int & Array:: operator[](int index)
{
	if(index>0&&index<=size)
	{
		cout<<"Element on this Index";
		cout<<"("<<index<<") is : ";
		return ptr[index-1];
	}
	else
	{
		cout<<"Index Not Found"<<endl;
		ptr[index]=0;
		return ptr[index];
	}
}
Array::~Array()
{
	if(ptr!=NULL)
	 delete[] ptr;
	else
	 ptr=NULL; 
}
int main()
{
	int size,i,index,end;
	cout<<"Enter array size for Array 1 : ";
	cin>>size;
	if(size<0)
	 size=1;
	else
	 size=size; 
    int a1[size];
	for(i=0;i<size;i++)
	{
		cout<<"Enter element Index["<<i<<"] : ";
		cin>>a1[i];
	}
	Array ar1(a1,size);
	cout<<"Element of Array 1 : ";
	cout<<ar1;
	cout<<"\nLocal_Average of Array 1 : "<<ar1.get_local_avg()<<endl;
	cout<<"Enter array size for Array 2 : ";
	cin>>size;
	if(size<0)
	 size=1;
	else
	 size=size;
	int a2[size];
	for(i=0;i<size;i++)
	{
		cout<<"Enter element Index["<<i<<"] : ";
		cin>>a2[i];
	}
	Array ar2(a2,size);
	cout<<"Element of Array 2 : ";
	cout<<ar2;
	cout<<"\nLocal_Average of Array 2 : "<<ar2.get_local_avg()<<endl;
	cout<<"Global_Count Array Object : "<<Array::get_global_count()<<endl;
    cout<<"Global_Size : "<<Array::get_global_size()<<endl;
    cout<<"Global_Average : "<<Array::get_global_average()<<endl;
    ar1+ar2;
    ar1-ar2;
    cout<<"INCREMENT IN ARRAY 1 : ";
    ar1++;
    cout<<"DECREMENT IN ARRAY 2 : ";
    ar2--;
    cout<<"DISPLAYING ELEMENT OF ARRAY_2 IN RANGE"<<endl;
    cout<<"Enter start position : ";
    cin>>index;
    cout<<"Enter close position : ";
    cin>>end;
    cout<<"Result of Array 2 ";
    ar2(index,end);
    cout<<"DISPLAYING ELEMENT OF ARRAY_1 ON INDEX"<<endl;
    cout<<"Enter the Index to display : ";
    cin>>index;
    cout<<ar1[index]<<endl;
    cout<<"CHANGING ELEMENT OF ARRAY_1 ON INDEX"<<endl;
    cout<<"Enter the Index : ";
    cin>>index;
    if(index>0&&index<=size)
     cin>>ar1[index];
    else
	 cout<<"Index Not Found"<<endl; 
    cout<<"UPDATING ARRAY_1 : ";
    cout<<ar1;
    cout<<"\nLocal_Average of Array 1 : "<<ar1.get_local_avg()<<endl;
    cout<<"Global_Average : "<<Array::get_global_average()<<endl;
}
