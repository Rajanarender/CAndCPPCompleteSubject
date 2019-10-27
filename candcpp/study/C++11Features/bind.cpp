#include<iostream>
using namespace std;

#include<functional> //for bind() API

using namespace placeholders; // Only for Positional Arguments

int func(int a,int b)
{
	cout<<a<<","<<b<<endl;
	return a+b;
}

int main()
{
	auto x = bind(func,2,4); //similar to pthreads
	cout<<x()<<endl; // to call the function

	auto y = bind(func,_2,_1); //Positional Arguments
	cout<<y(100,200)<<endl;
}
