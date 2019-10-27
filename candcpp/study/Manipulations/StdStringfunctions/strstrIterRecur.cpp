#include<iostream>
using namespace std;
#include<string.h>

//Here 4 while loops(2strlen,1strcmp,1normal) - More Time complexity

char* func(char* s,const char* subs)
{
	if(s == NULL || subs == NULL) //Corner case
	{
		return NULL; //since return type is ptr
	}

	int l1= strlen(s);
	int l2 = strlen(subs);
	while(l2 <= l1)
	{
		if(strncmp(s,subs,l2) == 0) //we need to check only specific number of bytes(substring) in string
			return s;
		s++;  //For traversing through string
		l1--; //length of string keeps decreasing,V.V.Imp
	}
}

int main()
{
	//cout<<func("Gesl is a Big MNC","Big"); //Leads to Warning converting from const char* to char*
	char x[] = "Gesl is a Big MNC";
	char y[] = "Big";
	cout<<func(x,y);
}
