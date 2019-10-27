#include<iostream>
using namespace std;
#include<initializer_list>

/********************************************
intializer_list container class
********************************************/

class Test
{
	public:
		Test(initializer_list<string>y)
		{
			for(auto i:y)
			{
				cout<<i<<endl;
			}
		}
};

int main()
{
	Test t{"Apple","Orange"};
	initializer_list<int>x{1,5,7};
	for(auto i: x)
	{
		cout<<i<<endl;
	}
}
