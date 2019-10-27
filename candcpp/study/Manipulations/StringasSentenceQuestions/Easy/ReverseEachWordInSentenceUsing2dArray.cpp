#include<iostream>
using namespace std;
#include<string.h>

/******************************************
Reverse Each Word in Sentence Using 2d Array
******************************************/

int main()
{
        const char *x="Global Edge is a MNC\nGlobal Edge is located in Tech Park\tTech Park is Good";
        char y[20][10]; //2d array with rows = Number of words[space+1]
        int j = 0; //rows
        int k = 0; //columns

	while (*x)
	{
		if(!(*x == ' ' || *x == '.' || *x == '\n' || *x == '\t')) //eliminating these 4 special characters
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

#if 0 //Method 1,Using strrev() API
        for(int a=0;a<=j;a++) //condition check with rows only
        {
                strrev(y[a]); //Reverse each word
        }
#endif

#if 1 //Method 2,Using columnwise reverse of each Word
        int len=0;
        int temp=0;
        for(int a=0;a<=j;a++) //condition check with rows only
        {
                len=strlen(y[a]);
                for(int col=0;col<len/2;col++) //Each column of Word
                {  //Here we are swapping only indexes
                        temp = y[a][col];
                        y[a][col] =y[a][len-1-col];
                        y[a][len-1-col]=temp;
                }
        }
#endif

        for(int a=0;a<=j;a++)
        {
                cout<<y[a]<<endl;
        }
}






