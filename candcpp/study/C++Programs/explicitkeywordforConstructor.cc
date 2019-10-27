#include<iostream>
using namespace std;

/*
explicit keyword is used ONLY for constructor declaration in class to avoid unwanted implicit type conversions
*/

class A
{
	public:
		explicit A(int x)
		{
			cout<<x<<endl;
		}

};

int main()
{
#if 0
	A a=10; //Since constructor is declared explicit,implicit type conversion is not allowed
#endif
	A a = A(10);
}
