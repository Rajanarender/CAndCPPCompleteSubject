#include<iostream>
using namespace std;

//1st scenario
#if 0 
class Base
{
	public:
		int x;
	protected:
		int y;
	private:
		int z;
};

class Derived: public Base
{

};

int main() //Only public members/public inherited can be accessed here strictly
{
	Derived d;
	d.x=10; 
	d.y=11; //protected member
	d.z=12; //private member
}
#endif


//2nd scenario:
#if 1
class Base
{

};

class Derived : public Base
{
	public:
		int x;
	protected:
		int y;
	private:
		int z;
};

int main() //Only public members/public inherited can be accessed here strictly
{
	Base *ptr = new Derived(); //Base ptr can access Derived only through virtual 

#if 0//Throws Error, Base class cannot see normal variables of Derived class
	ptr->x=10; 
        ptr->y=11; //protected member
	ptr->z=12; //private member
#endif
}
#endif

/*
Note: Base class ptr can access derived members only if there are virtual members of base
*/
#if 0 //3rd scenario:
class Base
{
public:
	virtual void func() //Base virtual function should be public always
	{
		cout<<"Im in Base\n";
	}

};

class Derived : public Base //Inheritance should be public always
{
	private: 
		void func() //Derived virtual function can be either public/protected/private
		{
			cout<<"Im in Derived\n";
		}
};

int main() //Only public members/public inherited can be accessed here strictly
{
	Base *ptr = new Derived(); //Base ptr can access Derived only through virtual 
        ptr->func();
}
#endif





