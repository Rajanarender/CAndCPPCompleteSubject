#include<iostream>
using namespace std;

void EvenOddfunc(unsigned int num)//Only +ve Numbers
{
	if(num%2 == 0)
		cout<<"Even Number\n";
	else if (num%2 == 1)
		cout<<"Odd Number\n";
}

NOTE: //0,1 are neither prime nor composite
//2 is a Prime Number
void PrimeCompositefunc(unsigned int num)
{
	int count =0;
#if 0
	for(int i=1;i<=num;i++) //V.V.Imp i value starts from 1,i=1,i<=num 
	{
		if(num%i == 0) //Successive reminder check
			count++;
	}
#endif
	for(int i=num;i>0;i--)
	{
		if(num%i == 0)
			count++;
	}

	if(count == 2) //V.V.Imp step,Count is 2, since any number can be divisible by 1 and itself
		cout<<"Prime Number\n";
	else if(count > 2)
		cout<<"Composite Number\n";
}

int Sqrtfunc(unsigned int)
{


}

//It supports 3digited number only like 153,371
void ArmstrongNumber(unsigned int num)
{
        int x=num;
	int res=0;
	while(x > 0)
	{
		res = res + (x%10)*(x%10)*(x%10);
		x = x/10; //x get affected, num will remain same
	}

	if(res == num)
		cout<<"ArmstrongNumber\n";
	else
		cout<<"Not ArmstrongNumber\n";
}

int main()
{
	int n;
	cout<<"enter a number\n";
	cin>>n;
/*
	EvenOddfunc(n);
        //cout<<Sqrtfunc(n);  
*/
        ArmstrongNumber(n);
        cout<<"Enter the No. of terms\n";      
        FibonacciSeries();
}
