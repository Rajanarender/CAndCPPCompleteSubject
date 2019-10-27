#include<iostream>
using namespace std;
#include<string.h>

/*************************************************************************************************
Anagram:Same length words with characters arranged in different order

=>1st check whether both the words are of equal length using strlen()
=>If both have equal both, then sort them using any sorting technique[bubble sort/selection sort]
=>After sorting,check whether both the words have equal ASCII values using strcmp()
=>If their ASCII values are equal,then they are Anagrams of each other
 ****************************************************************************************************/

void swap(char *m, char *n)
{
        char temp = *m;
        *m = *n;
        *n = temp;
}

void sort(char z[]) //Bubble Sort
{
        for(int i=0;i<strlen(z)-1;i++)
        {
                for(int j=0;j<strlen(z)-1-i;j++)
                {
                        if(z[j]>z[j+1])
                        {
                                swap(z[j],z[j+1]);
                        }
                }
        }
}


int main()
{
	char x[]="silent";
	char y[]="listen";

	if(strlen(x) == strlen(y))
	{
		sort(x);
		sort(y);

		if(strcmp(x,y) ==0)
		{
			cout<<"Given Words are Anagrams of each other"<<endl;
		}
		else
		{
			cout<<"Given Words are not Anagrams of each other because of different chracters"<<endl;
		}     
	}
	else
	{
		cout<<"Given Words are not Anagrams of each other because of unequal length"<<endl;
	}
}
