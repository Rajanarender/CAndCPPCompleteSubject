#include<iostream>
using namespace std;
#include<string.h>

/**************************************
=>if the lengths of words are different
sort them(Swap them )

=>if the lengths of words are same
strcmp words then
sort them
***************************************/

int main()
{
        const char *x="Global Edge is a MNC\nGlobal Edge is located in Tech Park\tTech Park is Good";
        char y[20][10]; //2d array with rows = Number of words[space+1]
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

        char temp[20];  //size of temp is = number of rows of 2d array
        for(int a=0;a<=j;a++) //condition check with rows only
        {
                for(int b=a+1;b<=j;b++) //condition check with rows only
                {
                      if(strlen(y[a])>strlen(y[b])) //Arranging in Ascending Order of lengths,V.V.Imp
                        {
                            strcpy(temp,y[a]); //Swapping smaller array element to the left side
                            strcpy(y[a],y[b]);
                            strcpy(y[b],temp);
                       }
                       else  if(strlen(y[a]) == strlen(y[b])) //When lengths are equal then go for ASCII strcmp(),V.V.Imp
                       {
                        if( strcmp(y[a],y[b])>0 ) //here y[a] > y[b],V.V.Imp
                        {
                            strcpy(temp,y[a]); //Swapping smaller array element to the left side
                            strcpy(y[a],y[b]);
                            strcpy(y[b],temp);
                        }
                     }
                }
        }

        for(int a=0;a<=j;a++)
        {
                cout<<y[a]<<endl;
        }
}
