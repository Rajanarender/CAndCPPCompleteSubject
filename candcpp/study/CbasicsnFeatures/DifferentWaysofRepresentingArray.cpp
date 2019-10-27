#include<iostream>
using namespace std;

/************************
x[n] =n[x] =*(x+n)
************************/

int main()
{
	int x[5]={1,2,3,4,5};
        cout<<*(x+0)<<endl; //This ptr prints the base address only
        cout<<*(x+1)<<endl; //x[1]
	cout<<1[x]<<endl; //x[1]
        //cout<<x<<endl;
	cout<<(x+3)[2]<<endl; //This prints 32767

	cout<<25u-50<<endl; //Some big number
}
