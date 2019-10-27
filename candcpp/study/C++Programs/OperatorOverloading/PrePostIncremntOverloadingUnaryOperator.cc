#include<iostream>
using namespace std;

/*************************************
X& operator++() //++obj
{
++i; // i is class member
}

X& operator++(int dummy) //obj++
{
i++;// i is class member
}
*************************************/
#if 1
class X
{
	int i;
	public:
	X():i(0)
	{}

	X(int a):i(a)
	{}

	X& operator++() //Pre-increment operator overloading
	{
		++i;
		cout<<"Pre-increment: "<<i<<endl;
		//return *this; //Not necessary
	}

	//X& operator++(int)
	X& operator++(int dummy) //Post-increment operator overloading, 
		//one argument of int type should be passed mandatorily
	{
		i++;
		cout<<"Post-increment: "<<i<<endl;
		//return *this; //Not necessary
	}

	void display()
	{
		cout<<i<<endl;
	}
};

int main()
{
	X x(4),y(9);
	++x;//Pre-increment
	x.display();
        y++;//Post-increment
        y.display();
	return 0;
}
#endif


