#include<iostream>
using namespace std;

#if 0
void FibonacciSeries(int trm)
{
	int trm;
	cout<<"Enter the no. of terms: ";
	cin>>trm;
	int first=0,second=1,next=0;
	for(int i=0;i<trm;i++)
	{
		if(i<=1)//if terms is 1,i=0, //if terms is 2, i =0,i=1
		{              
			next = i;
		}
		else
		{
			next=first+second;
			first=second;
			second=next;
		}
		cout<<next<<endl;
	}
}
#endif


#if 1  //Fibonacci series Recursion
int Recurfunc(int n)
{
	if(n==0 || n==1)
	{
		return n; 
	}

	return(Recurfunc(n-1) + Recurfunc(n-2)); //f(n-1)+f(n-2)
}

void func(int trm)
{
	for(int i=0;i<trm;i++)
	{
		cout<<Recurfunc(i); //We need to pass each term as argument to recursive func and print its return value
                cout<<endl;
	}
}

int main()
{
	int trm;
	cout<<"Enter the no. of terms: ";
	cin>>trm;
	//FibonacciSeries(trm);
	func(trm); //function used to call Recursion func
}
#endif
