#include<iostream>
using namespace std;


int func()
{
	int m =10;
	return m;
}

int main()
{
#if 1 //static variables initialization
	static int x = 10;

	int m=10;
	static int y=m;

	static int z=func();
	cout<<x<<" "<<y<<" "<<z<<" "<<endl;
#endif

#if 1 //const variables initialization
	const int a = 10;

	int k=10;
	const int b=k;

	const int c=func();
	cout<<x<<" "<<y<<" "<<z<<" "<<endl;
#endif
}
