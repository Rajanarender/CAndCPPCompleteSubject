#include<iostream>
using namespace std;

/************************************************************************************
functors:
It is like a function, which is called when object is overloaded with "()" operator
*************************************************************************************/

class Test
{
	public: 
		int operator()(int x) //functor
		{
			return x;
		}
};

int main()
{
	Test obj; //Test obj(20); //This will call the parameterised constructor
	cout<<obj(20)<<endl;
}
