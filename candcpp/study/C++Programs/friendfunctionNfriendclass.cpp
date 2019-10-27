#include<iostream>
using namespace std;

/**************************************************************************
friend function:
This function can access public,protected,private members of the class in which it is declared as friend

NOTE:
=>Normal functions can access only public members of the class
=>We cannot access friend functions using object.(dot) operator
obj.func //This is wrong

friend class:
This class can access public,protected,private members of the other class in which it is declared as friend
***************************************************************************/

class Test
{
	//public:
	//protected:
	private:
		int y; //Here y can be public/protected/private
		friend int func();
		friend class Trump;
};

class Trump //friend class
{
	public: //V.V.Imp,This should be public,since we call this func1 from main
		int func1()
		{
			Test obj1;
			obj1.y=200;
			return obj1.y;
		}

};


int func() //friend function
{
	Test obj;
	obj.y = 100;
	return obj.y;
}

int main()
{
	cout<<func()<<endl;
	Trump t;
	cout<<t.func1()<<endl;
}

