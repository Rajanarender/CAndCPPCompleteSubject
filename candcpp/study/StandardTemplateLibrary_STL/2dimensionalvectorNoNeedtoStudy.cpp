#include<iostream>
using namespace std;
#include<vector>


int main()
{
	//vector<int>v; //1D
	int Rows = 4,Columns=5,value=2;
	vector< vector<int> >v(Rows,vector<int>(Columns,value)); //2D

	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++) //v[i].size() each column size
		{
			cout<<v[i][j];
		}
		cout<<endl;
	}
}
