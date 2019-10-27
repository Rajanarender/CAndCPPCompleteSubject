#include<iostream>
using namespace std;

//nullptr constant
void func(int x)
{
	cout<<"In func(int x)"<<endl;
}

void func(int *x)
{
	cout<<"In func(int *x)"<<endl;
}

int main()
{
#if 0
	func(NULL); //Ambiguous Error
#endif
	func(nullptr); //To Resolve this Ambiguous Error,Use nullptr
        
        char *y= nullptr;
        int *z= nullptr;
        cout<<*y<<*z<<endl; //Segmentation fault,y and z dont have address
}
