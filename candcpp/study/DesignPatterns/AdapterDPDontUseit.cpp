#include<iostream>
using namespace std;

/******************************************************
Adapter Design Pattern:
Adapter class inherited from both Target[public] and Adaptee[private]

=>Converting the interface of a class to other interface which the client want

Here incompatiable interfaces are Target,Adaptee
They work together with the help of Adapter class
NOTE: client(main()) interacts only with the Target class
Target is public inheritance,Adaptee is private inheritance
******************************************************/
class Target
{
	public:
		virtual void display() = 0;
};

class Adaptee
{
#if 0
	int x;
	int y;
	public:
	Adaptee(int i ,int j ):x(i),y(j)
	{
		cout<<"In constructor of Adaptee class with x:"<<x<<" y:"<<y<<endl;
	}
#endif
	public:
	void func()
	{
		cout<<"In func() of Adaptee class"<<endl;
	}
};

class Adapter:public Target,private Adaptee //Adaptee is private inheritance
{
	public:
#if 0
	Adapter(int a,int b):Adaptee(a,b)
	{
	}
#endif
		Adapter()
		{

		}

		void display()
		{
			func(); //This is private member to Adapter class, we can access using public member display()
		}


};

int main()
{
#if 0
	Target *t = new Adapter(10,20); //This calls Adaptee constructor
#endif
        Target *t = new Adapter();
	t->display();//This calls Adaptee func();
}

 
