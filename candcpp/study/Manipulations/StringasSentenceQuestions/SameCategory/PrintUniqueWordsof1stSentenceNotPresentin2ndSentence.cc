#include<iostream>
using namespace std;
#include<string.h>

int main()
{
        const char *x="Global Edge Mindtree\nAccenture NTTData\tMphasis Sonata";
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

        const char *n="Global Edge is a MNC";
        char z[20][10]; //2d array with rows = Number of words[space+1]
        int c = 0; //rows
        int d = 0; //columns

        while (*n)
        {
                if(*n == ' ' || *n == '.' || *n == '\n' || *n == '\t')
                {
                        z[c][d]='\0'; //Completion of Each WORD
                        c++; //Increment rows
                        d=0; //Reset columns to 0

                        n++; //V.V.Imp, Whenever these characters come,Move the 'x' position to next position
                }

                if(*n != '\0')
                {
                        z[c][d]= *n; //Filling the 2d array
                        d++; //increment columns
                }
                n++;
        }
        z[c][d]='\0'; //Completion of Last WORD

        bool flag = false;
        for(int a=0;a<=j;a++) //condition check with rows only
        {
                for(int b=0;b<=c;b++)
                {
                        if( strcmp(y[a],z[b]) != 0 )
                        {
                                flag = true;
                        }
                        else
                        {
                                flag = false;
                                break; //V.V.Imp
                        }
                }
#if 1 //For unique Words in 1st sentence
                if(flag == true)
                {
                        cout<<y[a]<<endl;
                }
#endif

#if 0 //For same Words in both 1st sentence and 2nd sentence
                if(flag == false)
                {
                        cout<<y[a]<<endl;
                }
#endif
        }

}


