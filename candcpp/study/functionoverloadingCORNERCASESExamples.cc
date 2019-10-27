#include<iostream>
using namespace std;

/***************************************************
function overloading throws Ambiguous Error for 
int 
float

with default arguments
No arguments

function overriding: 
Same syntax exactly should be matched, only differ in body/content
int func(int a);
int func(long a); //Error
***************************************************/

#if 0
void func(short x)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}

void func(long x)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}
#endif

#if 0 //func(10.5) throws ambiguious Error for int, float
void func(int x)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}

void func(float x)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}
#endif

#if 0
void func(int x) //Works fine, for int,double
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}

void func(double x)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}
#endif

#if 0 //redefinition Error,when func is called with/without passing arguments
void func(int x =0)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}

void func(int x)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}
#endif

#if 1 //ambiguous Error when func is called without passing arguments
void func(int x =0)
{
	cout<<__LINE__<<" ,value: "<<x<<endl;
}

void func()
{
	cout<<__LINE__<<" ,value: "<<endl;
}
#endif

int main()
{
//func(100.0); //for int,double param works fine, but int,float throws ambiguity Error
func(200); //ambiguous Error for func with default arguments and without parameters
}
