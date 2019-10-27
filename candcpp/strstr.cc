#include<iostream>
using namespace std;
#include<string.h>


char* func(char* str,char* x)
{
	char* baseaddr = x;
	int count = 0;
	while(*str)
	{
		x=baseaddr;
		while(*x == *str)
		{
			count++;
			str++;
			x++;
		}

		if(*x == '\0')
		{
			return (str-count);
		}
		else 
		{
			count=0;
		}

		str++;
	}
	return NULL; //If substring is not found
}

int main()
{
	char* str = "Global Edge is a MNC";
	char* x = "E";
	//cout<<strstr(str,x);
	cout<<func(str,x);
}
