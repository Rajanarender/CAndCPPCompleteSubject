#include<iostream>
using namespace std;

/************************************************************
Converting Rows of a Matrix to Columns is Transpose Matrix
************************************************************/

int main()
{
        int x[2][2]={
                {2,3},
                {4,5}
             };

        int row =2,col=2;

#if 0
        int t[2][2]; //Transpose Matrix
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<col;j++)
                {
                        t[j][i]=x[i][j]; //Copy Each Row element of Given Matrix to Column of Transpose Matrix
                }

        }
#endif

#if 1 //Transpose of matrix
        for(int j=0;j<col;j++) //1st loop for cols
        {
                for(int i=0;i<row;i++) //2nd loop for rows
                {
                        cout<<x[i][j]<<",";
                }
                cout<<endl;
        }
#endif
}
