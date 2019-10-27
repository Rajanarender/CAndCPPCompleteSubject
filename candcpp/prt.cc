#include<iostream>
using namespace std;
#include<string.h>


char* func(char *s, char *delim)
{

	while(*s)
	{
                while(*s != *delim)
                {
                    delim++;
                }

		if(*s == *delim)
		{

			*s = '\0'; //V.Imp step,After making NULL only we have to return the string
			return (s-count);
		}

		count++;
		s++;
	}
       return (s-count);


}

int main()
{
	char x[] = "Gesl@is !a$MNC";
#if 0
	char *tok = strtok(x,"@!$ ");
	while(tok)
	{
		cout<<tok<<endl;
		tok = strtok('\0',"@!$ ");
		//tok = strtok(NULL,"@!$ ");
	}
#endif

	char *tok = func(x,"@!$ ");
	while(tok)
	{
		cout<<tok<<endl;
		tok = func('\0',"@!$ ");
	}
}
