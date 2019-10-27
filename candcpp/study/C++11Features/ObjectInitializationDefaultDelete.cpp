#include<iostream>
using namespace std;

/*****************************************************
default keyword
delete  keyword
default initialization of variables, instead of initializing in constructor
*****************************************************/

class Test
{
	int x{100}; //Default intialization to variable without using constructor
        int z[4]{10,20,3,50};
	string y{"Hello"};//Default intialization to variable without using constructor

	public:
        //Making all these member funtions declarations default,so that Programmer does not try to overload/customize them
	Test()=default;
	Test(const Test&)=default;
	Test &operator = (const Test&)=default;
        ~Test()=default;

/*
        //Making all these member funtions declarations delete,so that Programmer doesnot try to create,copy,assign objects to other
	Test()=delete;
	Test(const Test&)=delete;
	Test &operator = (const Test&)=delete;
        ~Test()=delete;
*/

	void display()
	{
		cout<<x<<" "<<y<<endl;
                cout<<z[0];
	}
};

int main()
{
	Test obj;
	obj.display();
}
