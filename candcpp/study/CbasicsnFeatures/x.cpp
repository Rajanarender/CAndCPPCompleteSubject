#include<iostream>
using namespace std;

int main()
{
	//int arr[5]={2,4,6,8,9};
//	int (*ptr)[5]= &arr; //&arr,here '&' should be used definitely,or else throws Error[casting of int to int*]
        
        int x=10;
        int *p1 = &x;
        
        int y=20;
	int *p2 = &y;
	int (*ptr)[2] = {&p1,&p2};

	cout<<ptr[0];
	cout<<ptr[1];

       }
