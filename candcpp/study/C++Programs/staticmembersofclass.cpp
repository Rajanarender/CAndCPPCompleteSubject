#include<iostream>
using namespace std;

#if 0
class X
{
	public:
		static int a;
		static int func();
};
int X::a=10;
int X::func() //Since a is of same class member, no need to pass parameter
{
	return a;
}

int main()
{
  cout<<X::func()<<endl;//static is non-member of class,so we cannot use class object to access it,A::staticmember[variable or func]
  cout<<sizeof(X)<<endl; //static is non-member of the class, so it is not considered for the class size
}
#endif

class X
{
	public:
		static int a; //should be public ,so that it can be accessed in another class
};

int X::a=10;

class Y
{
	int b;

	public:
	int func()
	{
		b = X::a; //static member of class X can be accessed in class Y
		return b;
	}

};

int main()
{
	Y obj;
	cout<<obj.func()<<endl;

}










