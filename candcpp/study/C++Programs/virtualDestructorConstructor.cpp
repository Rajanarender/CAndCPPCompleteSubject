#include<iostream>
using namespace std;

/************************************************************
virtual Destructor:
When the base ptr points to Derived class and try to delete 
this base ptr,only the base class destructor is called and base object is deleted but the derived object remains existed. 
This may lead to Memory leak.

To avoid this,to delete the derived object make the base class destructor virtual.
This would call both derived as well as base destructor to delete both the objects.

virtual Constructor:
This does not exist
Reason 1:
For any virtual concept,vptr is needed.
This vptr gets initialized in the constructor
So, if we make the constructor virtual,then vptr is no more
That's the reason,we dont have virtual constructor

Reason2: //More appropriate explanation
In C++,compiler creates the object at Compile time since it knows the class type
If we make constructor virtual, compiler cannot create the object since it doesnot know the class type at compile time leading to Error

NOTE: 
virtual constructor can be achieved using Factory design pattern 
where the objects/instances are created based on the class type at run time
*************************************************************/

class Base
{
	public: //Mandatory
	virtual	~Base()
		{
			cout<<"In Base\n";
		}
};

class Derived:public Base //Mandatory public inheritance
{
	private: //Can be any specifier[public,protected,private]
		~Derived()
		{
			cout<<"In Derived\n";
		}

};

int main()
{
	Base *ptr = new Derived();
	delete ptr;
}
