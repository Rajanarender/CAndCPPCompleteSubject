#include<iostream>
using namespace std;

/*****************************************
Delete the Elements in Sorted Array(3rd Array)
=>Skip the repeated elements
=>Copy the remaining elements to New Array
*****************************************/

#if 0 //Moving the elements to 3rd array
int main()
{
        int a[10]={2,2,2,4,4,7,9,9,10,11};
        int temp[6],j=0,i=0;
        for(;i<9;i++) //Since we compare 2elements take N-1
        {
                if( a[i] == a[i+1] ) //skip repeated elements
                        continue;
                else
                 {
                        temp[j]=a[i];
                        j++;
                 }
        } // By the end of this loop both i & j are incremented
        temp[j]=a[i];//V.V. imp step,copy the array last index to temp

        for(int i=0;i< ( sizeof(temp)/sizeof(temp[0]) ); i++)
        {
                cout<<temp[i]<<",";
        }
}
#endif

#if 1 //Moving the elements to same array
int main()
{
        int a[10]={2,2,2,4,4,7,9,9,10,11};
        int n=10;
        for(int i=0;i<n;i++) //Since we compare 2elements take N-1
        {
                if (a[i] == a[i+1])
                {
                        for(int k=i;k<n;k++)
                        {
                                a[k]=a[k+1]; //Copy the next element to previous position
                        }
                        n--; //Due to shifting, the size keeps decreasing,V.V.Imp
                        i--; //When the elements are equal, the index should be moved to its previous position,V.V.Imp
                }
        }

        for(int i=0;i<n;i++)
        {
                cout<<a[i]<<",";
        }
}
#endif

/*****************************************
Delete the Elements in UnSorted Array
*****************************************/

#if 0  //Moving the elements to same array
int main()
{
        int a[10]={2,4,7,6,7,8,2,4,1,6};
        int n=10;
        for(int i=0;i<n;i++) //Since we compare 2elements take N-1
        {
                for(int j=i+1;j<n;j++) //V.V.Imp
                {
                        if (a[i] == a[j])
                        {
                                for(int k=j;k<n;k++)
                                {
                                        a[k]=a[k+1];
                                }
                                n--;
                                j--;
                        }
                }
        }

        for(int i=0;i<n;i++)
        {
                cout<<a[i]<<",";
        }
}
#endif















