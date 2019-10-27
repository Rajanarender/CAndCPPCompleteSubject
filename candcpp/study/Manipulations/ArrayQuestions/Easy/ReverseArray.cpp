#include<iostream>
using namespace std;

int main()
{
        int x[]={2,4,6,8,0,1};
        int i=0,j=5; //Indexes starting from 0
        while(i<j)
        {
                int temp=x[i]; //Swapping x[i],x[j]
                x[i]=x[j];
                x[j]=temp;

                i++;
                j--;
        }

        for(int k=0;k<6;k++)
        {
                cout<<x[k]<<",";
        }
}
