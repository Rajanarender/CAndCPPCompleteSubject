#include<iostream>
using namespace std;

//Moving the unique No's to extra space,new array and then copying to existing array
int main()
{
        int a[10]={1,2,18,6,10,4,2,108,76,2};

        int temp[7],j=0;
        for(int i=0;i<10;i++)
        {
                if(a[i] == 2) //skipping 2
                        continue;

                temp[j] = a[i]; //Extra Array is used here
                j++;
        }

        for(int i=0;i< ( sizeof(temp)/sizeof(int)); i++)
        {
                cout<<temp[i]<<",";
        }

}
