#include<iostream>
using namespace std;

/******************************************************************************************
  How do initialize or access protected and private members of class from outside the class 
  We can make use of these members via public members(like constructor,member functions)
 *******************************************************************************************/

class X
{
	public:
		int a;
#if 1 //We can initialize protected,private members via publice members functions 
		void display(int m,int n)
		{
			b=m;
			c=n;
		}
#endif

#if 0 //We can initialize all class members using constructor
		X(int m,int n)
		{
			b=m;
			c=n;
		}
#endif
	protected:
		int b;
	private:
		int c;
};

int main()
{
	X obj;
	obj.a=10; //public member, so we can initialize it
#if 0
	obj.b=20; //Error, protected members cannot be initialized outside the class
	obj.c=30; //Error, private members cannot be initialized outside the class
#endif
	obj.display(20,30);
}
