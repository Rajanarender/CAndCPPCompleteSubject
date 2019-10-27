#include<iostream>
using namespace std;

//Using array of class objects
class X
{
	public:
		X()
		{
			cout<<"Hello"<<endl;
		}
};

int main()
{
	X obj[10]; //This will call the constructor 10times
}
