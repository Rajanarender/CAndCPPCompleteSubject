#include<iostream>
using namespace std;

#include<vector>

class X
{
	public:
		void func()
		{
			cout<<"Hi\n";
		}
};

int main()
{
	vector<X*>v;
	vector<X*>::iterator it;
	for(it=v.begin();it !=v.end();it++)
	{
		v.func();
	}

}
