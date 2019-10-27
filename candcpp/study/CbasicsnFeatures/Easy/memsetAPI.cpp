#include<iostream>
using namespace std;
#include<string.h>

/*
sizeof(datatype), the parameter inside sizeof() should be some data type 
*/

int main()
{
	char x[]="Global Edge";
	cout<<x<<endl;
	memset(x,0,sizeof(char)*strlen(x));//V.V.Imp step
	cout<<x<<endl; //All bytes set to zero

#if 0 //Do not use memset for ptr
	char *y="Global Edge";
	cout<<y<<endl;
	memset(y,NULL,sizeof(char)*strlen(y)); //We are clearing the address,which leads to NULL ptr
	cout<<y<<endl;//Dereferencing the NULL ptr will lead to Segmentation fault
#endif
}
