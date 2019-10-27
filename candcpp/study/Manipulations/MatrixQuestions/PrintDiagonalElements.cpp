#include<iostream>
using namespace std;

int main()
{
/*
        int x[4][2]={
                {2,3},
                {10,7},
                {1,8},
                {5,-1}
        };
*/
        int x[2][3]={
                {2,3,6},
                {10,7,9},
                //{1,8,4},
                //{5,-1,8}
        };

        int row=2,col=3;

        int i,j;
        for(int k =0;k<row;k++)
        {
                i=k;
                j=0;
		while(i>=0 && j<col) //V.V.Imp
		{
			cout<<x[i][j]<<endl;
			i--;
			j++;
		}
		cout<<endl;
	}

	for(int k =1;k<col;k++) //k=1,since 0th column is already covered in the above for loop
	{
		j=k;
		i=row-1; //V.V.Imp, diagonal starts from the last row to the first low
		while(j<col) //V.V.Imp
		{
			cout<<x[i][j]<<endl;
			i--;
			j++;
		}
		cout<<endl;
	}
}
