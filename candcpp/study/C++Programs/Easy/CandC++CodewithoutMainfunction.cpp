#include<iostream>
using namespace std;


//#define func main //loading func with main
// (or)
#define func m##a##i##n //Toke-Pasting Operator ##

//int main()
int func()
{
	cout<<"Global Edge\n";
	//printf("Global Edge\n");
	{
		int x =10;
	}
	cout<<x<<endl; //Error, since x scope is within that block, so not visible in this LOC
}
