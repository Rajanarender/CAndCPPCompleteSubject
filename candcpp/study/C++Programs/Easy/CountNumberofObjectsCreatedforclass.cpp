#include<iostream>
using namespace std;

//static variable is shared amoung all the objects of the class

class Test
{
	static int count; //V.V.Imp,Make it private,so that derived class does not affect it
	public:
	Test()
	{
		count++;
	}
        
        //void display()
	static void display()
	{
		cout<<"No. of objects created is: "<<count<<endl;
	}
};

int Test::count=0; //return type is must since it is a declaration with initialisation

int main()
{
	Test a,b,c,d;
	//a.display();
        Test::display();
        return 0;
}
