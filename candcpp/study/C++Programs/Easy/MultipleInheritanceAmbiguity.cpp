#include<iostream>
using namespace std;

/*****************************
Multiple Inheritance: 
Multi-Parents,Single-Child

When both the parents have the same func() and the child tries to access the function,
This leads to Ambiguous Error

Solution:
Call the function using "respective parent class name with scope resolution operator" 
C obj;
obj.A::func();
obj.B::func();
*****************************/

class A
{
	public:
		A()
		{
			cout<<"A constructor\n";
		}
		~A()
		{
			cout<<"A destructor\n";
		}

		void func()
		{
			cout<<"A func()\n";
		}

};

class B
{
	public:
		B()
		{
			cout<<"B constructor\n";
		}
		~B()
		{
			cout<<"B destructor\n";
		}

		void func()
		{
			cout<<"B func()\n";
		}

};

class C:public A,public B //Constructor call follows inheritance order
{
	public:
		C()
		{
			cout<<"C constructor\n";
		}
		~C()
		{
			cout<<"C destructor\n";
		}
};

int main()
{
	C obj;
	//c.func(); //Ambiguous Error,since both the parents have the same function
	obj.A::func(); // This will call class A func()
	obj.B::func(); // This will call class B func()
}

/*
o/p:
A constructor
B constructor
C constructor
C destructor
B destructor
A destructor
*/


