#include<iostream>
using namespace std;

/*
void func(int *m, int *n) //Swapping 2 numbers using function
{
	int temp = *m; //V.V.Imp,temp should be normal int only
	*m = *n;
	*n = temp;
}
*/

auto func = [](int *m, int *n) //Swapping 2 numbers using lambda expression
{
	int temp = *m; //V.V.Imp,temp should be normal int only
	*m = *n;
	*n = temp;
};

class Test
{
	int a{50};
	int b{60};

	public:
	Test()
	{
		auto f=[this]() // a,b are class members,we cannot directly access them in lambda expression,pass this in []
		{
			cout<<a<<","<<b<<endl; 
		};
		f();
	}
};

int main()
{
	Test obj;
	//cout<<obj.f();// We cannot call lambda expression using class object
	int x=10,y=20;
	cout<<"Before Swapping: x and y are: "<<x<< ","<<y<<endl;
	func(&x,&y);        
	cout<<"Before Swapping: x and y are: "<<x<< ","<<y<<endl;
        

	[=]() mutable //capture by value
	{
         x = 15; //mutable is used to change the global variables while using Capture by value, or else Error occurs
         y = 55;
	}();
	cout<<x<<","<<y<<endl;

	[&]() //capture by reference
	{
		x=-40;
		y=-60;
	}();
	cout<<x<<","<<y<<endl;

	[=,&x]() //capture by value,reference
	{
		x=70;
	}();
	cout<<x<<","<<y<<endl;

	[&,x]() //capture by reference,value
	{
		y=45;
	}();
	cout<<x<<","<<y<<endl;
}
