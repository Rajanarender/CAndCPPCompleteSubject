#include<iostream>
using namespace std;

/*****************************************************
Object slicing:
Direct Converting derived class object to base class object leads to this issue

Problem:
Base b = d; //Direct assignation,statically 
b.display(); //This calls base class function only

Solution 1: Use reference
Base &b = d;
b.display(); //This calls Derived class function

Solution 2: Use dynamic_cast
Base *b = dynamic_cast<Base*>(&d);
b->display(); //This calls Derived class function

NOTE: Inheritance + atleast one virtual function should be there, to get Object slicing Problem

NOTE: 
Conversion of base to derived is not possible,lower byte data to higher byte data
Downcasting is not possible,It leads to Error
*****************************************************/

class Base
{
	public:
		virtual void display()
		{
			cout<<"In Base\n";
		}
};

class Derived:public Base
{
	public:
		void display()
		{
			cout<<"In Derived\n";
		}
};

/*
void func(Base &b)
{
	b.display();
}
*/

int main()
{
#if 0 //This is the problem
	Derived d;
	Base b = d; //This leads to Object Slicing, derived fuction is not called 
#endif

#if 0 //Using base reference
	Derived d;
	Base &b = d; //This avoids object slicing
	b.display();
#endif

#if 0 //Using dynamic_cast
	Derived d;
        Base &b = dynamic_cast<Base &>(d);
             //(or)
        //Base &b = static_cast<Base &>(d);
        b.display();
#endif 
#if 1  //Using dynamic_cast
	Derived d;
	Base *b =dynamic_cast<Base*>(&d);
              //(or)
	//Base *b =static_cast<Base*>(&d);
	b->display();
#endif
	//func(d);

#if 0
        //Conversion of base to derived is not possible,lower byte data to higher byte data
        Base b;
        Derived d=b;
        Derived &d =b;
        Derived &d =dynamic_cast<Derived&>(b); //Segmentation fault
        Derived *d = dynamic_cast<Derived*>(&b);  
        d->display(); //Segmentation fault
#endif 
}
