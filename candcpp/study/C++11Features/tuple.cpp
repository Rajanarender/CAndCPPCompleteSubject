#include<iostream>
using namespace std;
#include<tuple> //for tuple

//g++ -std=c++11 xxx.cpp,To compile C++11 files
//g++ -std=gnu++11 xxx.cpp,To compile C++11 files

/*****************************************************
tuple: It holds difference heterogenous types of data
******************************************************/

int main()
{
	tuple<int,double,char>t(100,2.5,'B'); //It can be t{100,2.5,'B'}
                    //(or)
//	auto t = make_tuple(100,2.5,'B'); //auto takes the data type from rvalue

	cout<<get<0>(t)<<endl;
	cout<<get<1>(t)<<endl;
	cout<<get<2>(t)<<endl;
}
