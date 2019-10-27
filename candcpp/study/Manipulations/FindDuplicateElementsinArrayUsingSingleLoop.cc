#include<iostream>
using namespace std;

int main()
{
	int x[6]={10,15,4,20,20,15};
	int temp[20]={0}; //Index of temp = element of x

	for(int i=0;i<6;i++)
	{
		temp[x[i]]++;
    
		if( temp[x[i]] > 1 ) //V.V.Imp, Condition check should be here only, not before temp[x[i]]++
		{
			cout<<"Duplicate Element Found: "<<x[i]<<endl;
		}
	}
}
