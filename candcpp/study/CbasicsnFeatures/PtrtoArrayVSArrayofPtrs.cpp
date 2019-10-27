#include<iostream>
using namespace std;

int main()
{

/**************************
Ptr to Array[int,char]
**************************/

#if 1 //pointer pointing to int Array
	int x[] ={1,2,3,4};
	int *p = x;//*p=x[0]//base address
	while(*p)
	{
		cout<<*p<<endl;
		p++;
	}
#endif

#if 1 //pointer pointing to char Array
	const char *x ="global";
	const char *p =x; //*p='g'
	while(*p)
	{
		cout<<*p<<endl;
		p++;
	}
#endif

/**************************
[int,char]Array of ptrs
**************************/

#if 1 //int array of ptrs
	//int x[]={2,4,6};
	int a =2,b=4,c=6;
	int *m[] ={&a,&b,&c}; //Array of ptrs holds elements Addresses only
	for(int i=0;i<3;i++)
	{
		cout<<*m[i]<<endl; //*m[i], should use *
	}
#endif

#if 1 //char array of ptrs, its a 2d array
        const char *n[]={"Global","Edge"}; //Nothing but 2d array
	for(int i=0;i<2;i++)
	{
		cout<<n[i]<<endl; //only n[i],should not use *
	}
#endif

}
