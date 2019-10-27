#include<iostream>
using namespace std;

/************************************************************************************************
virtual functions:
Only the Base class virtual function arguments are considered and passed to the Derived class 
The Derived virtual function arguments are not at all considered

Default arguments are substituted at Compile time but the virtual func of derived is called 
at run time
************************************************************************************************/

class Base
{
	public:
		virtual void func(int x=10,int y=30) //This arguments are considered, not derived
		{
			cout<<"In Base: "<<x<<" , "<<y<<endl;
		}
};

class Derived:public Base
{
#if 1 //We can use any of these also
		//virtual void func(int x,int y)
		//virtual void func(int x,int y=50)
		//virtual void func(int x=100,int y) //Error,We cannot use this
#endif
	        virtual void func(int x=100,int y=50)
		{
			cout<<"In Derived: "<<x<<" , "<<y<<endl;
		}
};

int main()
{
	Base *ptr = new Base();
	ptr->func(); //10,30
	ptr = new Derived();
	ptr->func(); //10 , 30
}
