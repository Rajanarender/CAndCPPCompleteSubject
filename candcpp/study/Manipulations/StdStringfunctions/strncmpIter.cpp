#include<iostream>
using namespace std;

int func(char *m, char *n,size_t sz)
{
	while(*m && *n && sz) //Checking character by character till NULL character
	{
		if(*m != *n) //V.Imp condition
		{
			break; //Mandatory
		}
		m++;
		n++;

		sz--;
	} //This code comes out of loop when *m or *n or both become NULL
	return(*m-*n);//ASCII value difference
}

int main()
{
    char x[] = "RAjZ";//ASCII value for [a to z]= 97 to 122
    char y[] = "RajA";//ASCII value for [A to Z]= 65 to 90
    cout<<func(x,y,2)<<endl;
}
