#include<iostream>
using namespace std;
#include<string.h>

/*****************************************************
Overloading L-value and R-value References

move constructor same as copy constructor with && 
move assignment operator same as assignment constructor with && 

NOTE:
We can avoid deep copy using move constructor and move assignment operator
******************************************************/

#if 0
void func(int &x)
{
	cout<<"lvalue reference: "<<x<<endl;
}

void func(int &&x)
{
	cout<<"rvalue reference: "<<x<<endl;
}

int main()
{
	int a = 10; //lvalue
	//int &b = a; //lvalue reference
	//int &&c = a; //rvalue reference
	func(a);
	func(20);
}
#endif

#if 0
class X
{
	public:
		X()
		{
			cout<<"In Default constructor\n";
		}

		X(const X& obj)
		{
			cout<<"In Copy constructor\n";
		}

                X& operator = (const X& obj)
		{
			cout<<"In Assignment constructor\n";
		}

		X(const X&& obj)
		{
			cout<<"In Move constructor\n";
		}

	       ~X() //Destructor will be called for each constructor and assignment operator
		{
			cout<<"In Destructor\n";
		}

};


int main()
{
	X a,b=a,c=std::move(a),d;
        d=b; //Assignment operator will never call destructor
}
#endif

#if 1
class X
{
	int l;
	char *s;

	public:

	X(char *p)
	{ 
                l = strlen(p);
		s = new char[l+1];
		strcpy(s,p);
		cout<<"In Param constructor\n";
	}

	X(const X& obj)
	{
		l = obj.l;
		s = new char [l+1]; 
		strcpy(s,obj.s);
		cout<<"In Copy constructor\n";
	}

	X(const X&& obj)
	{
		s = obj.s;
		//strcpy(s,obj.s);
		cout<<"In Move constructor\n";
	}

	X& operator = (const X&& obj)
	{
		s = obj.s;
		//strcpy(s,obj.s);
		cout<<"In Move Assignment Operator\n";
	}

	void display()
	{
		cout<<s<<endl;
	}

};


int main()
{
        char k[] ="Gesl";
	X a(k),b=a,c=std::move(a),d(k);
        d = std::move(a);
        a.display();
        b.display();
        c.display();
        d.display();
}
#endif



