include<iostream>
using namespace std;
#include<string.h>

/*******************************************************
Definition:[Object Creation Based on type/class Name]
Main Objective "Creating objects for other classes based on the decision taken by the Derived class"
 (or)
Main Objective "Derived class will create objects for other classes based on their type"
This is Structural Design pattern
We are defining an interface class for creating an object,
in which only derived/subclasses will decide which class object should be instantiated

Client(main() function) should not create the objects of vehicles[car,Bike] directly
It interacts with Factory class which in turn creates the objects of vehicles
Here Factory class decides which Vehicle class objects need to be created

virtual constructor is achieved by using Factory Design pattern
Example:
Ecommerce is Factory class
Paytm is SubFactory class

Transaction -Base class

Derived classes like:
Credit Card(CC)
Debit Card(DC)
Cash On Delivery(COD)

Based on the transaction type,Factory will create & implement 
Derived classes CC,DC,COD

NOTE:
Always return new classname since the return type is classname*
********************************************************/

class Vehicle //Create a ptr object for this in main()
{
	public:
		virtual void func()=0;
};

class Car: public Vehicle
{
	public:
		virtual void func()
		{
			cout<<"Vehicle is Car"<<endl;
		}
};

class Bike: public Vehicle
{
	public:
		virtual void func()
		{
			cout<<"Vehicle is Bike"<<endl;
		}
};

class Factory  //Create a ptr object for this in main() 
{
	public:
		virtual Vehicle *create(const char*) = 0;
};

class subFactory:public Factory 
{
	public:
		Vehicle *create(const char *x)
		{
			if(strcmp(x,"Car") ==0)
				return new Car(); //Creation of Car
			else if(strcmp(x,"Bike") ==0)
				return new Bike(); //Creation of Bike
		}
};


int main() //This is client
{
	Factory *f= new subFactory;
        Vehicle *v;
	v = f->create("Car");
	v->func();
	v = f->create("Bike");
	v->func();
}

/*
//O/p: 
Vehicle is Bike
Vehicle is Car
*/


