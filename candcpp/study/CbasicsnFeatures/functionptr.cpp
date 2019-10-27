#include<iostream>
using namespace std;

/************************************************************
If we want to pass a function as parameter to other function,
we need function ptr.

function ptr is a ptr that points to func address location

NOTE: function ptr and callback functions should have same syntax with return type and arguments of same data type
*************************************************************/

#if 1 //Simple Example
int func(int m)
{
	return m;
}

int main()
{
#if 0 //fptr declaration and assignation together
	int (*fptr)(int)=func; //func holds the address implicitly,so need to pass &func
#endif 

#if 0 //fptr declaration and assignation separately
	int (*fptr)(int);
	fptr = func;
#endif 
	printf("%d , %d\n",(*fptr)(5),fptr(5));
}
#endif

int func( int x)
{
	return x;
}

void get(int (*func)(int x)) //This is function ptr used in definition
{
	int y = func(10);
	cout<<y<<endl;
}

int main()
{
	get(func); //Here only function name should be passed
}



int f1(int x)
{
return x;
}

//Ways of representing fptrs
int (*func)(int a) = f1;
cout<<func(10);

int (*func)(int a) = &f1;
cout<<(*func)(10);

int (*func)();
func = f1;
cout<<func();

int (*func)();
func = &f1;
cout<<(*func)();
