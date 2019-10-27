#include<iostream>
using namespace std;

char* func(char* d, char* s , size_t sz )
{
	char* temp = d;
	while(sz)
	{
		*d++ = *s++;
		sz--;
	}
	return temp; //return temp only and not d
}

int main()
{
	char src[] = "Global";
	char dest[6] ={0};
	cout<<func(dest,src,4)<<endl;
	cout<<dest<<endl;
}
