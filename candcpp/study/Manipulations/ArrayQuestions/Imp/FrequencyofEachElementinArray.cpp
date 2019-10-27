#include<iostream>
using namespace std;

int main()
{
        int x[]={2,3,3,2,4,6,7,1,7};
        int flag =0;
        int count =1;

        for(int i=0;i<9;i++)
        {
#if 1 //V.V.Imp
                for(int j=0;j<i;j++)
                {
                        if(x[i] == x[j])
                        {
                                goto label;
                        }
                }
#endif
                for(int j=i+1;j<9;j++)
                {
                        if(x[i] == x[j])
                        {
                                count++;
                        }
                }
                if(count ==1)
                {
                        cout<<x[i]<<"=>"<<count<<endl;
                }
                else
                {
                        cout<<x[i]<<"=>"<<count<<endl;
                        count =1; //Reset the count
                }
label:; //V.V.Imp
        }
}
