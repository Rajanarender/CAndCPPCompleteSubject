#include<iostream>
using namespace std;
#include<math.h>

int main()
{
/*1
	int num =4;
	int fact =1;
	for(int i=num;i>0;i--)
	{
		fact=fact*i;
	}
	cout<<fact<<endl;
*/
	int base;
	int exponent;
	cout<<"Enter Base: ";
	cin>>base;
	cout<<"Enter Exponent: ";
	cin>>exponent;
	int res=1;
#if 0
	for(int i=exponent;i>=1;i--)
	{
		res=res*base;
	}
#endif

#if 1
	for(int i=0;i<exponent;i++)
	{
		res=res*base;
	}
#endif

        cout<<"Power func result is: "<<res<<endl;
        cout<<pow(base,exponent)<<endl; //pow() API
        return res; 
}
