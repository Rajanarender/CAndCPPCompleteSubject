#include<iostream>
using namespace std;


int main()
{
	int num;
	cout<<"Enter the number\n";
	cin>>num;

	if((num&1) == 0)
        //if((num%2) == 0)
	{
		cout<<"Even\n";
	}
	else
	{
		cout<<"Odd\n";
	}
}
