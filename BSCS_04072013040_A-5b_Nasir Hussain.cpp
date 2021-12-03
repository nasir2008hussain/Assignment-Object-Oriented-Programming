#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Point{
	int p1;
	int p2;
	public:
		Point(){
		}
		Point(int P1,int P2){
			p1=P1;
			p2=P2;
		}
};
class Shape{
	protected:
		double pi = 3.14159265359;
	public:
		Shape();
		virtual double Calc_Area();
		virtual void draw();
		virtual ~Shape();
};
Shape::Shape(){
}
void Shape::draw()
{
	cout<<"DRAW_SHAPE\n";
}
Shape::~Shape(){
}
double Shape::Calc_Area()
{
	return 0;
}
class Line:public Shape{
	protected:
		Point P1,P2;
	public:
		Line();
		Line(Point p1,Point p2);
		virtual void draw();
		virtual ~Line();
};
Line::Line(){
}
Line::Line(Point p1,Point p2):P1(p1),P2(p2)
{
}
void Line::draw()
{
	cout<<"Geometric Shape : LINE\n";
}
Line::~Line(){
}
class Circle:public Shape
{
	protected:
		double r;
		Point p;
	public:
		Circle();
		Circle(Point P,double R);
		virtual double Calc_Area();
		virtual void draw();
		virtual ~Circle();
};
Circle::Circle(){
}
Circle::Circle(Point P,double R):p(P)
{
	r=R;
}
double Circle::Calc_Area()
{
	return (pi * pow(r,2));
}
void Circle::draw()
{
	cout<<"Geometric Shape : CIRCLE\n";
}
Circle::~Circle(){
}

class Triangle:public Shape
{
	protected:
		int x;
		int y;
		double angle;
	
	public:
		Triangle();
		Triangle(int a,int b,double A);
		virtual double Calc_Area();
		virtual void draw();
		virtual ~Triangle();
};
Triangle::Triangle(){
}
Triangle::Triangle(int a,int b,double A)
{
	x=a;
	y=b;
	angle=A;
}
double Triangle::Calc_Area()
{
	angle=(angle * (pi / 180));
	return (x*y)*(sin(angle)/2);
}
void Triangle::draw()
{
	cout<<"Geometric Shape : TRIANGLE\n";
}
Triangle::~Triangle(){
}
class Square:public Shape
{
	protected:
		double x;
	public:
		Square();
		Square(double side);
		virtual void draw();
		virtual double Calc_Area();
		virtual ~Square();
};
Square::Square(){
}
Square::Square(double side)
{
	x=side;
}
void Square::draw()
{
	cout<<"Geometric Shape : SQUARE\n";
}
double Square::Calc_Area()
{
	return pow(x,2);
}
Square::~Square(){
}
void drawshape(Shape* _shape[],int size)
{
	for(int i=0;i<=size;i++)
	{
		_shape[i]->draw();

	}
}
void Calculate_Areas(Shape* _shape[],int size)
{
	for(int i=0;i<=size;i++)
	{
     cout<<"Area is : "<<_shape[i]->Calc_Area()<<endl;
	}
	
}
int main()
{
	Shape* _shape [3];
	Point p1(0,0), p2(10,10);
    _shape[0]=new Line(p1,p2);
	_shape[1]=new Circle(p1,2.1);
	_shape[2]=new Triangle(4,5,45.8);
	_shape[3]=new Square(3.5);
	cout<<"-----------------------\n      DRAW_SHAPE()\n-----------------------"<<endl;
    drawshape(_shape,3);
    cout<<endl;
    	cout<<"-----------------------\n    CALCULATE_AREAS()\n-----------------------"<<endl;
    Calculate_Areas(_shape,3);
    delete _shape;
}
