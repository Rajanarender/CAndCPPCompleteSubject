#include<iostream>
using namespace std;
#include<string.h>

int main()
{
        const char *x="Global Edge is a MNC\nGlobal Edge is located in Tech Park\tTech Park is Good";

//This is used for all sentence related questions
#if 1 //2d array declaration and Rows,columns filling. Each Row contains a complete Single Word

        char y[20][10]; //2d array with rows = Number of words (or) total no. of spaces+1 , columns = strlen(maxcharacters word)+1
        int row = 0; //rows
        int col = 0; //columns

        while (*x)
	{
		//if(*x != ' ' || *x != '.' || *x != '\n' || *x != '\t') //NEVER USE THIS condition
		if(!(*x == ' ' || *x == '.' || *x == '\n' || *x == '\t')) //space characters ,! with all or conditions
                //if(isalpha(*x)) // we can use this also
		{ 
			y[row][col]= *x; //Filling the 2d array
			col++; //increment columns
		}
		else
		{
			y[row][col]= '\0'; //Completion of Each WORD
			col=0; //Reset columns to 0,V.V.Imp
			row++; //Increment rows
		}
		x++;
	}
	y[row][col]='\0'; //Completion of Last WORD ,row and col gets updated here
#endif

	//char z[20] ="Tech"; //This is the word which we want to check its frequency
	int count = 0;
	for(int i=0;i<=row;i++) //Traverse each row
	{
		//if( strcmp(y[i],z)==0 ) //No need to specify columns
		if( strcmp(y[i],"Tech")==0 ) //No need to specify columns
		{
			count++;
		}
	}
	cout<<"The Given Word is repeated: "<<count<<endl;
}


