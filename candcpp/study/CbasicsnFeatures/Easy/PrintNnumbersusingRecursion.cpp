#include<iostream>
using namespace std;

void func(int n)
{
	if(n==0)
	{
		return;
	}
	cout<<n<<endl; //This prints 5,4,3,2,1
	func(n-1);
	cout<<n<<endl; //Stack Reverses Here, So This prints 1,2,3,4,5
}

int main()
{
	int n;
	cout<<"Enter N: ";
	cin>>n;
	func(n);
}
