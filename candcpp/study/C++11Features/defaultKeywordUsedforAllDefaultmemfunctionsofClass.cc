#include<iostream>
using namespace std;


/***********************************************************************************************
When we write Param constructor,we call obj(10)
but if we call obj, It throws compilation Error as Compiler does not give us Default constructor

NOTE:
using default keyword, we can force the compiler to define default constructor explicitly
All Default members of the class can be explicitly defined using default keyword
default keyword used not be used for Any Default members of class holding user defined arguments
Eg:
X(int a) = default //Error, Param constructor cannot be made default 
*************************************************************************************************/

class X
{
	public:
#if 0 //No need to define default constructor
		X() {}
#endif

		X() = default; //Just declaration is enough, We are forcing the compiler to provide Default constructor Explicitly

		X(const X&) = default;
		X& operator=(const X&) = default;
		~X() =default;

		X(int a)
		{
			cout<<"Param Constructor\n";
		}
};

int main()
{
	X obj(10);
	X objj; //Compilation Error, No matching call ,Compiler doesnt provide Default constructor
}
