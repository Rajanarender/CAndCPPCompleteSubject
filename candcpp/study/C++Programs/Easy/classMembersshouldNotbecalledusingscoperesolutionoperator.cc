#include<iostream>
using namespace std;

class X
{
	public: 
#if 0   
		void func()
		{
			cout<<"In func\n";
		}
#endif
		static void init() 
		{
			cout<<"Global Edge\n";
		}
};

int main()
{
#if 0
	X::func();//Compilation Error,Member functions of the class should only be called using object
#endif
	X::init(); //static functions should be called using scope resolution operator only and not by class object
}
