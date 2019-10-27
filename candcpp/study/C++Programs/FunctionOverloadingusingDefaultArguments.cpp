#include<iostream>
using namespace std;

/********************************************************
  We can overload functions using default arguments
  We can override functions using default arguments

NOTE: We cannot overload/override static functions
 ********************************************************/

#if 0 //This leads to Error
int func(int x=10,int y)
{
	cout<<x<<endl;
}
#endif

void func(int x,int y=10) //Right side arguments should be intialized at any cost
{
	cout<<x<<" , "<<y<<endl;
}


int main()
{
	func(1);
	func(1,2);
}
