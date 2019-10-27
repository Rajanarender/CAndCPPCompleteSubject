#include<iostream>
using namespace std;

#include<stdlib.h>
#include<string.h>

/*********************************************************************************************
Given an array of n integers where n>1,return an array output such that
output[i] = product of all array[j] where i != j

i/p: {2,3,4}
o/p: {12,8,6}
*********************************************************************************************/

//void func(int *a,int* b,int n)
int* func(int *a,int* b,int n)
{
        int left =1;
        int leftArr[n];
        for(int i=0;i<n;i++)
        {
                leftArr[i] = left;
                left =left*a[i];
        }

#if 1 //1st Method,Using the argument of the function as productArray,INTERVIEW POINT
        int temp =1;
        b=(int*)malloc(sizeof(int*)*n);
        b=leftArr;
        for(int i=n-1;i>=0;i--)
        {
                b[i] = temp*b[i];
                temp =temp*a[i];
        }
       return b;

#if 0 //displaying the array elements
        for(int i=0;i<n;i++)
        {
                cout<<b[i]<<endl;
        }
#endif

#endif

#if 0 //2nd Method using rightArray and ProductArray
        int right =1;
        int rightArr[n];
        for(int i=n-1;i>=0;i--)
        {
                rightArr[i] = right;
                right =right*b[i];
        }

        int productArr[n];
        for(int i=0;i<n;i++)
        {
                productArr[i]= leftArr[i]*rightArr[i];
                cout<<productArr[i]<<endl;
        }
#endif

#if 0 //3rd Method using only ProductArray
        int temp =1;
        int *productArr=leftArr;
        for(int i=n-1;i>=0;i--)
        {
                productArr[i] = temp*productArr[i];
                temp =temp*b[i];
        }
        for(int i=0;i<n;i++)
        {
                cout<<productArr[i]<<endl;
        }
#endif

}

int main()
{
        int x[]={2,3,4};
        //func(x,x,3); //o/p:{12,8,6}

#if 0 //function returning the array
        int *m;
        m =func(x,x,3);
        for(int i=0;i<3;i++)
        {
                cout<<m[i]<<endl;
        }
#endif
}


