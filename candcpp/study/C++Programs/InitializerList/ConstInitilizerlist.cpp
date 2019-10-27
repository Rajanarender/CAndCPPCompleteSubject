#include<iostream>
using namespace std;

/****************************************************
Implement class members using const value

class members are:
=>default cons with initializer list
=>parameterised cons with initializer list
=>copy cons with initializer list
=>Assignment operator[Tell interviewer that we cannot implement it]
                     since const member cannot be modified
NOTE: Initializer list is mandatory
****************************************************/

class A
{
	const int y;
	public:

	A():y(0) //default Constructor
	{
	}

	//A(int k=0):y(k)//Behaves like dafault and Parameterised constructor
	A(int k):y(k)//Parameterised constructor
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
	A a,b(10),c(b),d;
        //d = a; //This is not allowed, since object d is already holding const value[0], 
                  //we cannot modify this const value 
	a.display();
	b.display();
	c.display();
        d.display();
}
