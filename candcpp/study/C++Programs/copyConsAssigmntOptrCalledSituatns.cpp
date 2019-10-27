#include<iostream>
using namespace std;

/***************************************************
When is copy constructor called:
=> When new object is created from existing class object
A obj1,obj2(obj1); //obj2=obj1
=> When object is passed by value to a function
A obj;
func(obj); //void func(A a)
=>When object is returned by value by a function
A obj1=func(),obj2=obj1; //A func()

When Assignment operator is called:
=> When one existing object is assigned to the other existing object
=> When object is returned by value by a function
A obj;
obj = func(); //A func()
****************************************************/
#if 0
class A
{
	public:
		int x;
		A()
		{
			cout<<"Default Constructor is called\n";
		}
		A(const A &obj)
		{
			cout<<"Default Copy Constructor is called\n";
		}
        
               A& operator =(const A &obj)
                {
			cout<<"Default Assignment Operator is called\n";
                }
};

A func()
{
        A ob; 
        ob.x = 100;
	return ob;
}

//void func1(A objt) this will call the copy constructor
void func1(A &objt) //reference object will avoid calling the copy constructor
{
	cout<<objt.x<<endl;
}

int main()
{
	A obj=func(),obj1=obj; //This calls copy constructor
        A obj2;
        obj2=func(); //This calls Assignment operator
	func1(obj); //This calls copy constructor
}
#endif

/***************************************
Simplest Answer is in below code
***************************************/

class Base
{
	public:
	int x;
		Base() :x(10)
	        {

                 cout<<"In Default constructor"<<endl;
	        }

		Base(const Base &obj)
		{
                 cout<<"In Copy constructor"<<endl;
		}

                Base& operator=(const Base &obj)
		{
                 cout<<"In Assignment operator"<<endl;
		}
};

//NOTE: const is not necessary for this arguments in func
//void func(const Base obj) //This will call the copy constructor,in projects we shouldn't use this syntax
void func(const Base &obj) //This will avoid calling the copy constructor,we can use this syntax
{
	cout<<obj.x<<endl;
}

Base& func1()
{
	Base *obj;
	cout<<obj->x<<endl;
	return *obj;
}

int main()
{
	Base b;
	func(b);
        b=func1();
     
        vector<Base>v;
        v.insert(v.end(),A(10)); //This calls constructor,copy constructor
        v.push_back(10);

        v.emplace(v.end(),10);//We can avoid copy constructor by using this emplace
        v.emplace_back(10);
}















