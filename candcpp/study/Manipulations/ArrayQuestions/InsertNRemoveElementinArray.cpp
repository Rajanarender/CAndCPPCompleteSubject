#include<iostream>
using namespace std;

int main()
{
        int x[]={2,4,6,8,1,3,7};
        int n =sizeof(x)/sizeof(x[0]);

#if 0 //Insertion
        int pos = 3;
        int element = 10;
        for(int i =n-1;i>=0;i--)
        {
                x[i+1]=x[i];
                if(i==pos-1)
                {
                        x[i]=element;
                        break; //V.V.Imp
                }
        }

        for(int i=0;i<n+1;i++)
        {
                cout<<x[i]<<",";
        }
#endif


#if 1 //Deletion
        int pos = 3;
        for(int i =0;i<n;i++)
        {
                if(i==pos-1) //Directly go to that position where we want to delete the element
                {
                        int j=i; //copy to local variable,V.V.Imp
                        while(j<n)
                        {
                                x[j]=x[j+1];
                                j++;
                        }
                        x[n-1] = 0; //V.V.Imp step
                        break; //V.V.Imp
                }
        }

        for(int i=0;i<n;i++)
        {
                cout<<x[i]<<",";
        }
#endif
}







