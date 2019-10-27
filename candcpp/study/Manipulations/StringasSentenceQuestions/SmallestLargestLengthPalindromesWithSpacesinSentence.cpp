#include<iostream>
using namespace std;
#include<string.h>
//#include<limits.h> //INT_MAX,INT_MIN

#if 1 //Just for idea,its a normal palindrome function
bool isPalindrome(char m[])
{
	char temp[20];
	strcpy(temp,m);
	strrev(temp); //strrev() Api doesnot work in this linux system
	if(strcmp(temp,m)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
#endif

#if 0 //Just for idea,This code does not work
bool isPalindrome(char x[][10],int a)
{
     int len=0;
	//for(int a=0;x[a];a++) //strlen()/2, V.V.Imp step
	{
		len= strlen(x[a]);
		for(int j=0;j<len/2;j++)
		{
			if( x[a][j] != x[a][len-1-j] )
			{
				cout<<"Given string is not a Palindrome"<<endl;
				return 0; //V.V.Imp step
			}
		}
	cout<<"Given string is a Palindrome"<<endl; //V.V.Imp step,Should be outside the loop
	return 1;
	}
}
#endif

#if 0
int main()
{
	const char *x="LiriL Edge is CiviC\nGlobal RacecaR is located in ROTATOR Park\tTech HaaH is MalayalaM";
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

#if 0 //Never use these macros for array,Instead we can use base index for initializing min and max value
	int min = INT_MIN;
	int max = INT_MAX;
#endif
	int min = 100; //V.V.Imp
	int max = 0; //V.V.Imp
	char maxword[20];
	char minword[20];
	for(int a=0;a<=j;a++) //condition check with rows only
	{

#if 1 //Palindrome Check code 
		int len =0;
		bool Palinflag= false;
		len= strlen(y[a]);
		for(int j=0;j<len/2;j++) //For each column/character in word till the half length
		{
			if( y[a][j] != y[a][len-1-j] )
			{
				Palinflag=false; //V.V.Imp step
				break; //To Come out of the loop
			}
			Palinflag=true; //V.V.Imp step, keep this flag as true within for loop only, not outside
		}

#endif           
		if( Palinflag == true )
		{
			cout<<"Palindrome Word is: "<<y[a]<<endl;
			if(strlen(y[a]) >= max)
			{
				max = strlen(y[a]);
				strcpy(maxword,y[a]); //Keep storing the maximum word always
			}
			if(strlen(y[a]) <= min)
			{
				min = strlen(y[a]);
				strcpy(minword,y[a]); //Keep storing the minimum word always
			}
		}
	}

	cout<<"Maximum/Largest Length Palindrome is: "<<maxword<<" => "<<max<<endl;
	cout<<"Minimum/Smallest Length Palindrome is: "<<minword<<" => "<<min<<endl;
}
#endif

#if 0  //Another way to find the count of palindromes in the sentence
bool Palindrome(char *start,char *end)
{
	while(start <= end) //V.V.Imp step
	{
		if(*start != *end)
		{
			return false;
		}
		start++; //for traversing,Imp step
		end--; //For traversing.Imp step
	}
	return true;
} 
#endif

#if 1
//For checking and getting the count of individual word Palindrome in the sentence
void func(char *x)
{
	char *w =x;
	char *temp=x;
	int count =0;
	while(*temp)
	{
		if(*temp == ' ')
		{
			if(Palindrome(w,temp-1))
			{
				count++;
			}
			w=temp+1; //Update the word ptr by changing its address
		}
		temp++;
	}
	if(Palindrome(w,temp-1))
	{
		count++;
	}
	cout<<"No. of Palindromes in the given Word are: "<<count<<endl;
}

int main()
{
	char x[]="LiriL Edge is CiviC";
	func(x);
}
#endif
