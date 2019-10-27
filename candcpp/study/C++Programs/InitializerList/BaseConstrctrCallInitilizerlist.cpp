#include<iostream>
using namespace std;

/*******************************************************
Initializer list:
Used in constructor,copy constructor for intializing 
any variable,Mandatory for const,reference variables
Used for calling base constructor from derived class
********************************************************/
class Base
{
	int z;
	public:
        Base()
        {}
	Base(int c):z(c)
	{}
	void display1()
	{
		cout<<z<<endl;
	}
};


class Derived:public Base
{
	int x;
	int y;
	public:
	Derived(int a,int b,int k):x(a),y(b),Base(k)
	{}
	void display2()
	{
		cout<<x<<", "<<y<<endl;
	}
};

int main()
{
	Derived d(2,3,9);
	d.display2();
        d.display1(); //9,since we are passing argument to Base class constructor
	Base b;
	b.display1();//this gives garbage value,it will call only default constructor
        Base b1(9); // this will be meaningless,as Parameterised constructor is called by Derived  
}
