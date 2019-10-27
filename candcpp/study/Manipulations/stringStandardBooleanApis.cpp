#include<iostream>
using namespace std;
#include<ctype.h>

/*********************************************************
Boolean functions that return true(1),false(0)
These functions are mainly used for checking/validating the characters
These function return true if they find the relavant data

isalpha()+isdigit()[0 to 9] = isalnum()[alphanumeric]
isupper()+islower() = isalpha()
isblank()+isspace()
isxdigit()[0 -9,a-f,A-F] - Hexadecimal format
isascii() - only ascii characters

NOTE:
=>sizeof(bool) is 1byte, similar to char
=>flags use bool data type

int toupper(),int tolower() -conversion to upper case,lower case
NOTE: return type for toupper(),tolower() is int
*********************************************************/

int main()
{
	const char *x="Global Edge@:3560\n\t1012";
	while(*x)
	{
		//cout<<(char)toupper(*x)<<endl;
		if(isupper(*x)) //(isupper(*x)==true)
		{
			cout<<*x<<endl;
		}

		if(islower(*x)) //(islower(*x)==true)
		{
			cout<<*x<<endl;
		}

		if(isalpha(*x)) 
		{
			cout<<*x<<endl;
		}

		if(isalnum(*x))
		{
			cout<<*x<<endl;
		}

		if(isdigit(*x))
		{
			cout<<*x<<endl;
		}

		if(isxdigit(*x))
		{
			cout<<*x<<endl;
		}

		if(isblank(*x))
		{
			cout<<(int)*x<<endl;
		}

		if(isspace(*x))
		{
			cout<<(int)*x<<endl;
		}
 
	        if(isascii(*x))
		{
			cout<<(int)*x<<endl;
		}

		x++;
	}
}
