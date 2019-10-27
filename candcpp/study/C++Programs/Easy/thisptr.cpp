#include<iostream>
using namespace std;

/**************************************************************
this ptr: [*this]
It is a const ptr pointing to the current object of the class
It is a hidden argument present in all default members[cons,copy cons,assignment,des] and non-static member functions

syntax:
TYPE const *this = &obj; //Address is fixed
 (or)
TYPE *const this = &obj; //Address is fixed

NOTE:
friend functions,friend class cannot access *this 
static functions cannot access *this

this pointer is used for avoiding self assignment of same class objects to each other
**************************************************************/

//Here class members and constructor variables are same, we can differentiate them using this ptr for class members
class X
{
	int a,b;
	public:
	X(int a,int b) 
	{
#if 0
		a=a;
		b=b;
#endif
		this->a = a;
		this->b = b;
	}

	int display() //member function of class
	{
		return (this->a + this->b);
	}

#if 0
	static int func() //We cannot use this ptr for static functions
	{

	}
#endif

};

int main()
{
	X obj(10,20);
        cout<<obj.display()<<endl;
}
