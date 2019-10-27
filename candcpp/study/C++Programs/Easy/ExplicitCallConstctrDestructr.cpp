#include<iostream>
using namespace std;

/****************************************************
Explicit Constructor call:
This will immediately call the destructor in the next line only
Scope of the object is small
A();

Explicit Destructor call:
A a;
a.~A();

Note:
We use A a; so that class object scope will be high
object gets destroyed automatically just before the main returns
object scope lies with the program
=>We do not use Explicit cons and des call
*****************************************************/
class A
{
	public:
		A()
		{
			cout<<"Constructor called\n";
		}

		~A()
		{
			cout<<"Destructor called\n";
		}
};

int main()
{
	A(); //Explicit Constructor Call
	//This leads to Constructor and immediate Destructor call automatically
	//Generally Destructor is called automatically before the main returns
	cout<<"Global Edge\n";
	A a;
	a.~A(); //Explicit Destructor Call
}

/*
o/p: 
Constructor called
Destructor called (due to Explicit Constructor call)
Global Edge
Constructor called(due to A a)
Destructor called(due to Explicit Destructor call)
Destructor called(due to A a) 
