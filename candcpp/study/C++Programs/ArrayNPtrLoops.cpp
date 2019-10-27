#include<iostream>
using namespace std;

void func(char *x) //ptr format
{
	char *baseaddr=x;
	while(*x)
	{
		cout<<"Index position: , character: "<<(x-baseaddr)<<","<<*x<<endl; //V.V.Imp, arr[i]=> *x,
                                                                                              //i=> (x-baseaddr) 
		x++;
	}
}

void func1(char x[],int n) //Array format, sizeof array is mandatory 
{
	for(int i=0;i<n;i++)
	{
		cout<<"Index position: , character: "<<i<<","<<x[i]<<endl;
	}
}

int main()
{
	char x[]="Global";
        func1(x,6); //Array format,sizeof array should be passed mandatorily
	func(x); //ptr format
}


#if 0 //Array format with Nested loops 
for(int i =0;i<N;i++)
{
	for(int j=0;j<N;j++) //This loop always starts from 0 
	{
	}
}
#endif

#if 0 //Ptr format with Nested loops
char *baseaddress=q;
#if 0 //We can write like this also
char *baseaddress;
baseaddress=q;
#endif

while(*p)
{
	while(*q)
	{
		q++;
	}
	q=baseaddress; //This makes q to start from baseaddress for each iteration,V.V.Imp

	p++;
}
#endif



