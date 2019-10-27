#include<iostream>
using namespace std;

/***********************************
Array Notation:
x[n]=n[x] =*(x+n)
***********************************/

//int func(int *x,int n)
int func(int x[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
#if 0 //Using ptr format
		sum = sum+ *(x+i);
#endif

#if 0  //using array format,V.V.Imp
		sum=sum+x[i];
#endif

#if 1  //using array format,V.V.Imp
		sum=sum+i[x];
#endif

	}
	return sum;
}

int main()
{
	int x[]={5,6,7,9};
	cout<<"Sum of all elements in Array: "<<func(x,4)<<endl;
}
