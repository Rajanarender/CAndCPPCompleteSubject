#include<iostream>
using namespace std;

int main()
{
        int x[]={5,10,6,3,8,1,7};
        int min =x[0]; //Assume minimum element as Base index of array
        int max =x[0]; //Assume maximum element as Base index of array

        for(int i=0;i<7;i++)
        {
		if(x[i] < min) //Imp step
		{
			min=x[i];
		}
		else if(x[i] > max) //Imp step
		{
			max = x[i];
		}
	}
	cout<<"Minimum Element in array is:"<<min<<endl;
	cout<<"Maximum Element in array is:"<<max<<endl;
}
