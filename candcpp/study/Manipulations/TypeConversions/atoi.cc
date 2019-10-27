#include<iostream>
using namespace std;
#include<stdlib.h> //for atoi()

#if 0
int func(char x[])
{
	int res = 0;
	for(int i=0;x[i] !='\0';i++)
	{
		res=res*10 + (x[i]-'0'); //'0' Ascii value is 48
	}
	return res;
}
#endif


int func(char *x)
{
	int res = 0;
	//while(*x)
	while(*x >= '0' && *x <= '9') //Ascii 0 to 9 only considered
	{
		res = res*10 + (*x-'0');
		x++;
	}
	return res;
}

int main()
{
	char x[]="1234A";
        cout<<atoi(x)<<endl; //1234
	char y[]="1234A567";
        cout<<atoi(y)<<endl; //1234
	char z[]="A1234";
        cout<<atoi(z)<<endl; //0
       
        char k[] = "1234A";
	cout<<func(x)<<endl;
}



#if 0
Example:
i/p: 123.456.78.9
o/p:123456789

int func(char x[])
{
	int res=0;
	for(int i=0;x[i] !='\0';i++)
	{
		if(x[i] == '.')
			continue;

		res=res*10+x[i]-'0';
	}
	return res;
}

int main()
{
	char x[]="123.456.78.9";
	cout<<func(x)<<endl;
}
#endif

