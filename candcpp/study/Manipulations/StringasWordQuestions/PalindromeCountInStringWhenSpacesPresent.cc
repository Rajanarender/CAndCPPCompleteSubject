#include<iostream>
using namespace std;

bool IsPalindromeCheck(char *begin,char *end)
{
       //char *palinstrt = begin;
       //char *palinend = end;
	while(begin < end) //address check
	{
		if(*begin != *end) //Value check
		{
			cout<<"Not a Palindrome"<<endl;
			return false; 
		}
		begin++;
		end--;
	}
	//cout<<palinstrt<<" is a Palindrome"<<endl;
	cout<<" is a Palindrome"<<endl;
        return true;
}

void func(char *x)
{
        char *baseaddr =x;
        static int count=0;
	while(*x)
	{
		if( *x == ' ')
		{
			if(IsPalindromeCheck(baseaddr,x-1) == true) //x-1 is V.V.Imp
				count++;

			baseaddr = x+1; //Always keep changing baseaddr
		}

		x++;
	}
	if(IsPalindromeCheck(baseaddr,x-1) == true) //since *x is NULL,we need to check the last word also
		count++;

        cout<<"Number of Palindromes in the sentence is: "<<count<<endl;
}

#if 0
void func(char *x)
{
	char *start=x;
        char *temp =x;
        static int count=0;
	while(*temp)
	{
		if( *temp == ' ')
		{
			if(IsPalindromeCheck(start,temp-1) == true)
				count++;

			start = temp+1;
		}

		temp++;
	}
	if(IsPalindromeCheck(start,temp-1) == true)
		count++;

        cout<<"Number of Palindromes in the sentence is: "<<count<<endl;
}
#endif

int main()
{
	char x[]="LIRIL MADAM BAAB";
	func(x);

}
