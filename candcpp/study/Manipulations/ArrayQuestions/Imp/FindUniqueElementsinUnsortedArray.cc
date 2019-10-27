#include<iostream>
using namespace std;

int main()
{
        int x[]={2,3,3,2,4,6,7,1,7};
        int flag =0;

        for(int i=0;i<9;i++)
        {
                for(int j=0;j<9;j++)
                //for(int j=i+1;j<9;j++) //Dont use it, since we need to check all the elements index from 0 onwards
                {
                        if(i==j)
				continue; //V.V.Imp

			if(x[i] != x[j]) //Unique elements
			{
				flag = 0;
			}
			else 
			{
				flag = 1;
				break;
			}
		}

		if(flag ==0)
		{
			cout<<"unique Elements in Array are: "<<x[i]<<endl;
		}
		else
		{
			cout<<"Duplicate Elements in Array are: "<<x[i]<<endl;
		}
	}
}
