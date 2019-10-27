#include<iostream>
using namespace std;

int main()
{
	int x =10,y=20;
	cout<<"Before Swapping: "<<x<<" "<<y<<endl;
        
#if 0 //Using 3rd variable temp
	int temp=x;
	x=y;
	y=temp;
	cout<<"After Swapping: "<<x<<" "<<y<<endl;
#endif

#if 0 //Using 3rd variable temp
	char temp=*x;
	*x=*y;
	*y=temp;
	cout<<"After Swapping: "<<*x<<" "<<*y<<endl;
#endif


#if 0 //Without 3rd variable,addition,substraction binary operators
	x=x+y; //V.V.Imp
	y=x-y; //10
	x=x-y; //20
	cout<<"After Swapping:"<<x<<" "<<y<<endl;
#endif

#if 0 //Without 3rd variable,bitwise XOR operator
	x=x^y;
	y=x^y;
	x=x^y;
	cout<<"After Swapping: "<<x<<" "<<y<<endl;
#endif
}
