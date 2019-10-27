#include<iostream>
using namespace std;

/**********************************************************
lambda expression:
It is a nameless function or function without any name
[](){}; //termination ";" is mandatory

[]() //func() 
{
	cout<<"lambda expression without parameter"<<endl;
}(); //lambda expression call without any name

auto f = [](int x) //lambda expression
{
	cout<<"lambda expression with parameter "<<x<<endl;
};

f(200); //lambda expression call with name

[]()->int // x's data type should be mentioned using ->datatype 
{
	cout<<"lambda expression without parameter"<<endl;
return x;
}(); //lambda expression call without any name

int globalvar =100;
[=]() mutable // use mutable keyword to make changes to globalvariable
{
globalvar=20;
}();
**********************************************************/


void callbackfunc(int x) //V.V.Imp,callback func definition
{
	cout<<"In Callback func "<<x<<endl;
        return ;
}

void g(void (*pfunc)(int x)) //function ptr
{
	pfunc(10);
        return ;
}

int main()
{
  //int var=0; 
	[]() //func() 
	{
		cout<<"lambda expression without parameter"<<endl;
                
	}(); //lambda expression call

	[](string s) //func() 
	{
		cout<<"lambda expression with parameter "<<s<<endl;
                
	}("Global"); //lambda expression call

//cout<<var;

	auto f = [](int x) //lambda expression
	{
		cout<<"lambda expression with parameter "<<x<<endl;
		return ;
	};

	f(200); //lambda expression call

	g(f); //Lambda expression as callback

	g(callbackfunc); //Normal callback function


	auto lmd = [](int x) ->char//lambda expression, we can specify the return type using arrow mark
	{
		return 65;
	};

	cout<<lmd(200)<<endl; //if we want return type to be int,float,char use "->int","->float","->char"
}









