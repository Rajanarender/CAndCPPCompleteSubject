#include<iostream>
using namespace std;

/****************************************************
Implement class members using reference variable
class members are:
=>default cons with initializer list[Tell interviewer that we cannot implement it]
 since reference variable should be initialized with variable and not value
NOTE: In default constructor,we cannot pass variable

=>parameterised cons with initializer list
=>copy cons with initializer list
=>Assignment operator[Tell interviewer that we cannot implement it]
                     since reference member cannot be modified

NOTE: Initializer list is mandatory

int m=10;
A a(m); //Object declaration should be like this 
A(int &k):x(k) //Parameterised constructor should be like this
****************************************************/

class A
{
        int &y; //reference member
	public:
/*
	A():y(0) //default Constructor,This is not allowed,because we cannot assign numeric value to reference variable directly
	{
	}
*/
	A(int &k):y(k)//Parameterised constructor
	{}

	A(const A &obj):y(obj.y) //copy constructor
	{}

	void display()
	{
		cout<<y<<endl;
	}
};

int main()
{
#if 0 //This is wrong since constructor is having reference as argument, so you shouldnt pass value directly
	A b(14),c(b);
#endif

#if 1
	int m=14;
	A b(m),c(b);
#endif

	//A a; //This is not allowed,since we cannot assign numeric value directly to reference 
	//b = c; //This is not allowed, since object b is already holding const value[0], 
	//we cannot modify this const value
	b.display();
	c.display();
}
