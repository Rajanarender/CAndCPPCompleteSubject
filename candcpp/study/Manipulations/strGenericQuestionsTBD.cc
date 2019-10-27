#include<iostream>
using namespace std;

/***********************************
Upper case to Lower Case
Lower case to Upper Case
***********************************/
char* func(char *s)
{
	while(*s)
	{
		if(*s >='A'&& *s <='Z') //65 to 90
		{
			*s=*s+32;
		}
		else if(*s >='a' && *s <= 'z' ) //97 to 122
		{
			*s=*s-32;
		}
		s++;
	}
	return s;
}

int main()
{
	char x[]="GloBalEdge";
	func(x); //Pass by Reference
        cout<<x<<endl;
}

/****************************************
Count the no. of vowels 





















