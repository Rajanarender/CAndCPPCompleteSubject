#include<iostream>
using namespace std;

#define func(x) {\
		typeof(x) k; \
		cout << (((char*)(&k+1))-((char*)(&k))) << endl; \
		}


int main()
{
#if 0 //With sizeof() operator
	cout<<sizeof(a)<<endl;
#endif 
	int a;
	func(a);

	char b;
	func(b); //1byte

	short c;
	func(c); //2bytes

	int j;
	func(j); //4bytes

	long l;
	func(l); //8bytes

	float d;
	func(d); //4bytes

	double e;
	func(e); //8bytes

	func(10);

}
