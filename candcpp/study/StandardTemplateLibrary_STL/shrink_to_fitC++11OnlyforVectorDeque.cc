#include<iostream>
using namespace std;
#include<vector>

/*****************************************************
resize() - Is present only in vector,deque
shrink_to_fit() - Is supported only in vector,deque
*****************************************************/

int main()
{
	vector<int>v(50);
	cout<<v.capacity()<<endl;//50
	cout<<v.size()<<endl; //50
	v.resize(10); //This will reduce size only
	cout<<v.size()<<endl; //10,size is reduced 
	cout<<v.capacity()<<endl;//50, still capacity is same
	v.shrink_to_fit();//This will reduce capacity only as per the size reduction
	cout<<v.capacity()<<endl; //10
	cout<<v.size()<<endl; //10
}
