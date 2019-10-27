#include<iostream>
using namespace std;
#include<string.h>

/***************************************
1st solution:
=>Bubble Sort in Asc order BBBBBGGGGGRRRR
=>String Reverse BGR, to get RRRRGGGGBBB

2nd solution:
=>Bubble Sort in Desc order RRRRGGGGBBB

Solution:
Use bubble sort with condition in reverse
***************************************/

void swap(int *m, int *n)
{
        char temp = *m;
        *m = *n;
        *n = temp;
}

int main()
{
        char x[]="BRGBRGBRGRGBRGB";
        for(int i=0;i<strlen(x)-1;i++)
        {
                for(int j=0;j<strlen(x)-1-i;j++)
                {
                        if(x[j]<x[j+1]) //This is for Descending Order,
                                        //In Bubble sort we use (x[j]>x[j+1]) for Ascending Order
                        {
                                swap( x[j],x[j+1] );
                        }
                }
        }

        for(int i=0;i<strlen(x);i++)
        {
                cout<<x[i];
        }
}


