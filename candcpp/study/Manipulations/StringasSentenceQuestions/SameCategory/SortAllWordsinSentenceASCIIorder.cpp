#include<iostream>
using namespace std;
#include<string.h>

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

        char temp[20];  //size of temp is = number of rows of double ptr
        for(int a=0;a<=j;a++) //condition check with rows only
        {
                for(int b=a+1;b<=j;b++) //condition check with rows only
                {
                        if( strcmp(y[a],y[b])>0 ) //here y[a] > y[b]
                        {
                                //We cannot use (=) for char array, use strcpy only
                                strcpy(temp,y[a]); //Swapping smaller array element to the left side
                                strcpy(y[a],y[b]);
                                strcpy(y[b],temp);
                        }
                }
        }

        for(int a=0;a<=j;a++)
        {
                cout<<y[a]<<endl;
        }
}
