#include<iostream>
using namespace std;

auto func() ->char
{
	int x=75;
	return x;
}

//template<class T>
template<typename T>
auto func1(T x) ->decltype(x)
{
	return x;
}

int main()
{
	auto i= 10;
	auto f= 20.55;
	auto c= 'A';
	auto s ="Global";
	cout<<func()<<endl;
        cout<<func1("Raja")<<endl;     
        cout<<func1(2)<<endl;     
}
