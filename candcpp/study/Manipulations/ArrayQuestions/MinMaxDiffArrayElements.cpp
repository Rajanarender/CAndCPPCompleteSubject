#include<iostream>
using namespace std;

/**************************************************
To find the max diff b/w 2 array elements
=>Sort the given array
=>After Sorting, find the max,min difference b/w 2 array elements
**************************************************/

void sort(int x[],int s)
{
        for(int i=0;i<s-1;i++)
        {
                for(int j=0;j<s-1-i;j++)
                {
                        if(x[j] > x[j+1])
                        {
                                int temp = x[j];
                                x[j]= x[j+1];
                                x[j+1] = temp;
                        }
                }
        }
}

int main()
{
        int x[]={6,5,4,17,9,3};
        sort(x,6);
        int maxdiff =0;
        int mindiff = 20;
        for(int i=0;i<6;i++)
        {
                for(int j=i+1;j<6;j++)
                {
                        if(x[j]-x[i] >= maxdiff)
                        {
                                maxdiff=x[j]-x[i];
                        }

                        if(x[j]-x[i] <= mindiff)
                        {
                                mindiff=x[j]-x[i];
                        }
                }
        }
        cout<<"maxdiff b/w 2 array elements is: "<<maxdiff<<endl;
        cout<<"mindiff b/w 2 array elements is: "<<mindiff<<endl;
}
