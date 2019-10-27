#include<iostream>
using namespace std;

/*********************************************
Compiler provides Default constructor, if user doesn't define any constructor(default,param,copy)

In case if the user defines his own constructor(param,copy), then compiler does not provide default constructor
NOTE: Uses has to write his own default constructor
*********************************************/

class X
{
	int k;
	public:
	X()
	{

		cout<< "Default constructor\n";
	}
	X(int a):k(a)
	{
		cout<< "Param constructor\n";
	}

};

int main()
{
	X obj; //Error since there is no matching call,When you dont define Default constructor
	X obj1(10);
}
