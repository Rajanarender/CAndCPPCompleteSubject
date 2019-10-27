#include<iostream>
using namespace std;
#include<vector>

/*********************************************************************
for(vector<int>::iterator it= v.begin();it != v.end();it++)

for(vector<int>::reverse_iterator it= v.rbegin();it != v.rend();it++) 
**********************************************************************/

int main()
{
	int x[]={2,4,6};
/*
	for(int i=0;i<3;i++)
	{
		cout<<x[i]<<endl;
	}
*/
	for(auto i: x) //i holds each element of array 
	{
		cout<<i<<endl;
	}

	char y[]="Global";
/*
	for(int i=0;y[i] != '\0';i++)
	{
		cout<<y[i]<<endl;
	}
*/
	for(auto i: y) //Here last character '\0' also gets displayed
	{
		cout<<i<<endl;
	}

	vector<int> v;
        v.push_back(2);
        v.push_back(4);
/*
	for(vector<int>::iterator it= v.begin();it != v.end();it++) //here iterator "it" is needed
	{
		cout<<*it<<endl; // This displays the vector elements starting from frontside
	}
*/
	for(vector<int>::reverse_iterator it= v.rbegin();it != v.rend();it++) //here iterator "it" is needed
	{
		cout<<*it<<endl; // This displays the vector elements starting from backside
	}

	for(auto i: v) //No need of iterator, we can use normally
	{
		cout<<i<<endl;
	}

	for(int i =0;i<2;i++)
	{
		cout<<v.back()<<endl; //This returns the elements starting from backside of vector
		v.pop_back(); //Only for removing the vector elements,this does not return anything
	}
}



