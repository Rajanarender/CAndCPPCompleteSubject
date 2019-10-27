#include<iostream>
using namespace std;

#if 0
void Factorialfunc(int n)
{
	int fact = 1;
	for(int i=num;i>0;i--)
	{
		fact = fact*i;
	}
	cout<<"Factorial of "<<num<<" is: "<<fact<<endl; //In C++,format specifiers(%d,%f,etc) cannot be used
}
#endif

//Recursive for factorial
int Recurfunc(int n)
{
	if(n == 0)
		return 1;

	return n*Recurfunc(n-1);
}

int main()
{

	cout<<"Enter the number: ";
        int num;
	cin>>num;
	cout<< Recurfunc(num);
	//Factorialfunc(num);
}
