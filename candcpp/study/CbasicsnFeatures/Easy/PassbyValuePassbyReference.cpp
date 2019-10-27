#include<iostream>
using namespace std;

void passbyValue(int x) //The passed value does not get affected
{
	x = 100;
}

void passbyReference(int &x) //The passed value gets affected due to reference
{
	x = 200;
}

int main()
{
	int a = 40;
	passbyValue(a);
        cout<<"a value is: "<<a<<endl; //40,since a value is not affected 
	passbyReference(a);
        cout<<"a value is: "<<a<<endl; //200,int &x=a,x value is changed in passbyReference
}


