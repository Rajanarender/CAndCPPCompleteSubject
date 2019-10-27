#include<iostream>
using namespace std;

#include<string.h>

int main()
{
	const char *x = "Global Edge Global MNC";
        char wrd[] = "Global";
	int count = 0;
        int ret;
	while(*x)
	{

		ret = strstr(x,wrd);
		if(!ret)
		{
			count++;
			x=ret+strlen(wrd);
		}
		x++;
	}
	cout<<count<<endl;
}
