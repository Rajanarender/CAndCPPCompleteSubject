#include<iostream>
using namespace std;

/*************************************************
final 
We can make the class not to be inherited 
We can make the function not to be overritten
*************************************************/
#if 0
class Base final //final keyword
{
	public:
		virtual void func() final //final keyword for func
		{
		}
};

class Derived:public Base
{
	public: //Optional 
		void func()
		{
		}
};

int main()
{
	Base obj;
}
#endif

/*************************************************
override
This indicates that the function is overridden 
from its derived class 
*************************************************/

class Base
{
	public:
		virtual void func()
		{
			cout<<"In Base\n";
		}
};

class Derived:public Base
{
	public://Optional
		void func() override //override keyword
		{
			cout<<"In Derived\n";
		}
};

int main()
{
	Base *ptr=new Base();
	ptr->func();
	ptr= new Derived();
	ptr->func();
}




















