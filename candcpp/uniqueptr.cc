#include<iostream>
using namespace std;
#include<memory>   //header for smart pointers

class Base
{
        int x;
	public:
		Base()
		{
			cout<<"In Base Constructor"<<endl;
		}
               Base(int a):x(a)
		{
			cout<<"In Base Parameterized Constructor "<<x<<endl;
		}
		~Base()
		{
			cout<<"In Base Destructor"<<endl;
		}
};

class Derived
{

};

int main()
{
//unique_ptr<Base>obj = new Base; //Error
unique_ptr<Base>obj(new Base); //Default constructor call
unique_ptr<Base>obj1(new Base(10)); //Parameterized constructor call

unique_ptr<Base>obj2 = make_unique<Base>();
unique_ptr<Base>obj3 = make_unique<Base>(10);

obj.reset(nullptr); //Default Destructor call


//obj.reset(new Derived); //Error
//unique_ptr<Base>obj(new Derived); //Error
}
