#include<iostream>
using namespace std;

#if 0
int Powerfunc(unsigned int base,int exponent)
{
	int res=1;
	for(int i=exponent;i>0;i--) //exponent is for iteration only,V.Imp
	{
		res=res*base;
	}
	return res;
}
#endif

//Recursion for pow() func
int Recurfunc(int b, int e)
{
	if(e ==0)
		return 1;

	return b*Recurfunc(b,e-1); //multiply with b, V.Imp
}

int main()
{
	int base,exponent;
	cout<<"Enter base: ";
	cin>>base;

	cout<<"Enter exponent: ";
	cin>>exponent;
	//Powerfunc(base,exponent);
	cout<<Recurfunc(base,exponent);    
}
