#include<iostream>
using namespace std;

int main()
{
        int x[3][3]={
                {2,4,6},
                {1,3,5},
                {7,8,9}
        };

        int row = 3,col = 3;
        int sum = 0;
        for(int i =0;i<row;i++)
        {
                for(int j=0;j<col;j++)
                {
                        if(i==j) //rowindex=columnindex for Primary Diagonal Elements
                        {
                                cout<<x[i][j]<<endl;
                                sum = sum+x[i][j];
                        }
                }
        }
        cout<<"Sum of All Primary Diagonal Elements of the Matrix is: "<<sum<<endl;
}
