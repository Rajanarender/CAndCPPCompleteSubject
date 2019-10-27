#include<iostream>
using namespace std;

int func(int num)
{
	if(num ==0)
		return 1;

	return num*func(num-1); //num-1 will be -ve, when num is 0,So write the if condition based on this
}

int main()
{
	cout<<"Factorial of a Number: "<<func(5);
}
