#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	const char *x="Global Edge is a MNC Global Edge is located in Tech Park Tech Park is Good is Global";
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

	int count=1; //Make count as 1
	for(int a =0;a<=j;a++) //condition check with rows only
	{
#if 1 //This is included so that the words in b/w will check whether its copy is repeated from the beginning of sentence till the word
      //If present it will be skipped 

		for(int b=0;b<a;b++) //V.V.Imp step, b<a ,leftside of a
		{
			if((strcmp(y[a],y[b])==0) )
			{
				goto label; //V.V.Imp step
			}
		} 
#endif
		for(int b=a+1;b<=j;b++) //V.V.Imp step
		{
			if( strcmp(y[a],y[b])==0 )
			{
				count++;
			} 
		}
		if(count == 1) //unique words count
		{
			cout<<y[a]<<"="<<count<<endl;
		}
		else //Repeatative/duplicate words count
		{
			cout<<y[a]<<"="<<count<<endl;
			count= 1; //V.V.Imp,Reset the count for the next coming word
		}
label:;  //V.V.Imp,since there are no statements after label,terminate(;) it 
	}
}
