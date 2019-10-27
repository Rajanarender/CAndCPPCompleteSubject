#include<iostream>
using namespace std;

/********************************************************************
Abstract Factory Method:
Main Objective "Derived class will create objects for other classes based on their similar family"

This is Creational Design Pattern
We are defining/writing a interface class for creating families of relevant objects without specifying their concrete/sub classes

Note: 2 subclasses are mandatory

Eg:
Micro -OlaMicro,UberMicro
Mini -OlaMini,UberMini

Cabs -Ola,Uber
Ola-OlaMicro,OlaMini [We should create families of same type]
UberCabs-UberMicro,UberMini [We should create families of same type]

Eg1: //Consider this Example V.V.Imp
MNC -Factory
Tcs -SubFactory1
Hcl -SubFactory2

Software
TcsSoft
HclSoft

Bpo
TcsBpo
HclBpo

NOTE:
Always return new classname since the return type is classname*
*******************************************************************/

class Micro //Create a ptr object for this in main()
{
	public:
		virtual void display()=0;
};

class Olamicro:public Micro
{
	public:
		void display()
		{
			cout<<"Olamicro\n";
		}
};

class Ubermicro:public Micro
{
	public:
		void display()
		{
			cout<<"Ubermicro\n";
		}
};

class Mini //Create a ptr object for this in main()
{
	public:
		virtual void display1()=0;
};

class Olamini:public Mini
{
	public:
		void display1()
		{
			cout<<"Olamini\n";
		}
};

class Ubermini:public Mini
{
	public:
		void display1()
		{
			cout<<"Ubermini\n";
		}
};

//Interface class creating families of relevant objects
class Cabs  //Create a ptr object for this in main()

{
	public:
		virtual Micro* func() = 0;
		virtual Mini* func1() = 0;
};

class Ola:public Cabs //only Ola family
{
	public:
		Micro* func()
		{
			return new Olamicro;
		}

		Mini* func1()
		{
			return new Olamini;
		}
};

class Uber:public Cabs //only Uber family
{
	public:
		Micro* func()
		{
			return new Ubermicro;
		}

		Mini* func1()
		{
			return new Ubermini;
		}
};

int main()
{
	Cabs *C;
	Micro *Mc;
	Mini *Mi;
#if 1 //This is Ola family
	C =new Ola; 
	Mc = C->func();
	Mc->display();
	Mi = C->func1();
	Mi->display1();
#endif

#if 1 //This is Uber family
	C =new Uber;
	Mc = C->func();
	Mc->display();
	Mi = C->func1();
	Mi->display1();
#endif
}


/*
O/p:
Olamini
Olamicro
Ubermini
Ubermicro
*/









