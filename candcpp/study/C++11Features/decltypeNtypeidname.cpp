#include<iostream>
using namespace std;
#include<typeinfo> //for typeid().name()

/*********************************************************
decltype() does not need header,default C++ supports it
typeid().name() need to include typeinfo header
typeid displays the data type of the variable at Run time
***********************************************************/


int main()
{
	int x =100;
	decltype(x) A =20; // A is of type int having same data type as that of x
	cout<<A<<endl;

	char y;
	decltype(y) B ='F'; // B is of type int having same data type as that of y
	cout<<B<<endl;

	string z;
	decltype(z) C="Global",D="Edge"; // C is of type int having same data type as that of z
	cout<<C<<endl;
	cout<<D<<endl;

	cout<<typeid(A).name()<<endl; //i
	cout<<typeid(B).name()<<endl; //c
	cout<<typeid(C).name()<<endl; //Ss
}
