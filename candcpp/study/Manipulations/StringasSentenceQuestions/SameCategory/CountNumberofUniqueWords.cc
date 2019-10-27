#include<iostream>
using namespace std;
#include<string.h>

int main()
{
	const char *x="Global Edge is a MNC Global Edge is located in Tech Park Tech Park is Good";
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

/*************************************************************
6steps to get the count of unique words in a sentence
int flag = false;
int count =1; //step1

for(int b=0;b<=j;b++) //step2
{
if(a==b)
continue; //step3
if( strcmp(y[a],y[b]) != 0 ) //unique words
{
flag =true; //step3
}
else //duplicate words,step4
{
flag=false;
break; //step5
}
}

if(flag == true) //Number of unique words
{
count++; //step6
cout<<"Unique Words are: "<<y[a]<<endl;
}
*************************************************************/

	bool flag = false;
	int count=1; //V.V.V.Imp,Make count as 1
	for(int a=0;a<=j;a++) //condition check with rows only
{
	for(int b=0;b<=j;b++) //V.V.V.Imp step, b should always start from Zero
	{
		if(a==b) //V.V.V.Imp step, Check for the same position and skip that WORD
		{
			continue;
		}

		if( strcmp(y[a],y[b]) !=0 ) //unique words
		{
			flag = true;
		}
		else //duplicate words
		{
			flag=false;
			break; //V.V.V.Imp step
		}
	}
	if(flag == true) //Number of unique words
	{
		count++;
		cout<<"Unique Words are: "<<y[a]<<endl;
	}
	if(flag == false) //Duplicate words
	{
		cout<<"Duplicate Words are: "<<y[a]<<endl;
	}
}
cout<<"Count  of Unique Words: "<<count<<endl; //V.V.Imp
}
