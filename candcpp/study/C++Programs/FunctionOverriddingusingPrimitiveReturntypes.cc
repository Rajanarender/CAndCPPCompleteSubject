#include<iostream>
using namespace std;

In overriding,SAME SYNTAX should be used along with return type

class X
{
public:
	virtual double func() //Error, same return type should be there
	{
		cout<<"double\n";
	}
};

class Y: public X
{
public:
	virtual int func()
	{
		cout<<"int\n";
	}

};

int main()
{
	X *ptr =new Y();
	ptr->func();
}
