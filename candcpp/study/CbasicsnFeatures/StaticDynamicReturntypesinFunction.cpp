#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>

char* func(const char *m) //Dynamic 
{
	char *ptr = (char*)malloc( sizeof(char)*(strlen(m)+1) );
	strcpy(ptr,m);
	return ptr;
}

char* func1() //Static
{
	char x = 'A';
        char *ptr = &x;

#if 0 //This leads to Segmentation fault
	char *ptr = (char*)'A'; //Characters,numbers direct assignation leads to segmentation fault
                                //Only strings can be directly assigned
#endif
	return ptr;
}


int main()
{
	cout<<func("Raja")<<endl;
	cout<<func1()<<endl;
}
