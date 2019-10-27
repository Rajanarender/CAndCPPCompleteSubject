#include<iostream>
using namespace std;

class X
{
	public:
		X()
		{
			cout<<"Default constructor\n";
		}

#if 0
		X(X obj); //error: invalid constructor
		X(const X obj); //error: invalid constructor,& is mandatory
#endif 
		//X(X &obj) //Without const also works fine
		X(const X &obj)
		{
			cout<<"Copy constructor\n";
		}

#if 0
                X operator=(X obj)
                X operator=(const X obj) //Works fine but calls copy constructor then assignment operator
#endif
                //X operator=(X &obj) //Without const also works fine
                //X operator=(const X &obj)
                X &operator=(const X &obj) //Mostly used syntax
		{
			cout<<"Assignment operator\n";
		}

		void func(X obj) //Why here without Reference it works fine ??
		{
			cout<<"func\n";
		}
};

int main()
{
	X a,b;
        b=a;
	//x::func(); //only when function is declared as static
	//a.func(a); //Any class member must be accessed using object only
}
