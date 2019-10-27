#include<iostream>
using namespace std;
#include<string.h>

int main()
{
        const char *x="Global Edge is a MNC\nGlobal Edge is located in Tech Park\tTech Park is Good"; //x++ is allowed
        char y[20][10]; //2d array with rows = Number of words[Number of spaces+1],columns = Word with max length
        int j = 0; //rows
        int k = 0; //columns

	while (*x)
	{
		if(!(*x == ' ' || *x == '.' || *x == '\n' || *x == '\t')) //space characters
		{ 
			y[j][k]= *x; //Filling the 2d array
			k++; //increment columns
		}
		else
		{
			y[j][k]='\0'; //Completion of Each WORD
			k=0; //Reset columns to 0,V.V.Imp
			j++; //Increment rows
		}
		x++;
	}
	y[j][k]='\0'; //Completion of Last WORD

	//char z[20] ="Global"; //This is the Word which needs to be replaced
	for(int a=0;a<=j;a++) //condition check with rows only
        {
                //if( strcmp(y[a],z) == 0 )
                if( strcmp(y[a],"Global") == 0 )
                {
                        strcpy(y[a],"Software"); //We can taken this word "Software" into an array and then strcpy()
                }
        }

        for(int a=0;a<=j;a++)
        {
                cout<<y[a]<<endl;
        }
}


