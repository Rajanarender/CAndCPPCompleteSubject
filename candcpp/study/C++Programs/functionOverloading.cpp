#include<iostream>
using namespace std;

/*************************************************
Function Overloading:
function with same name but with different data type/Number of arguments
Note:return type is not CONSIDERED,V.Imp

We can overload const function
We can overload function with default arguments
We can overload constructor of a class

Note: 
We cannot overload static functions
We cannot overload reference,value of same data type
We cannot overload const,normal variable of same data type
*************************************************/

#if 1 //We cannot overload const variable
void func(const int x)
{
	cout<<"In func(const)"<<x<<endl;
}

int func(int x)
{
	cout<<"In func()\n"<<x<<endl;
}
#endif

#if 1 //We cannot overload reference variable
void func1(int &x)
{
	cout<<"In func(const)"<<x<<endl;
}

int func1(int x)
{
	cout<<"In func()\n"<<x<<endl;
}
#endif

void func2(int x,int y=0)
//void func2(int x=0,int y) //This is Wrong
{
	cout<<"In func(const)"<<x<<" "<<y<<endl;
}


int main()
{
/*
	const int x =10; //Ambiguity due to this
        int y= 20;
	func(x);
	func(y);
*/
     //int k =100; //Ambiguity due to this
    //func1(k);
      func2(30);
      func2(10,20);
        
}
