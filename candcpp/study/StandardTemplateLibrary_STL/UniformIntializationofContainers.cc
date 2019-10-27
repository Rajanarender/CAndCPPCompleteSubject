#include<iostream>
using namespace std;

#include<vector>
#include<list>
#include<map>
#include<set>

int main()
{
	vector<string>v{"Global","Edge","MNC"}; //vector<string>v={"Global","Edge","MNC"};
	for(auto i:v)
	{
		cout<<i<<endl;
	}

	list<string>l{"Global","Edge","MNC"}; 
	for(auto i:l)
	{
		cout<<i<<endl; //vector displays elements in Ascending order
	}

	map<string,int>m={ {"Global",10},{"Edge",20},{"MNC",30} }; 
	for(auto i:m) //instead of iterator we can use this
	{
		cout<<i.first<<"=>"<<i.second<<endl; //map displays keys in Ascending order
	}

	set<string>s{"Global","Edge","MNC"}; 
	for(auto i:s)
	{
		cout<<i<<endl; //vector displays elements in Ascending order
	}
}
