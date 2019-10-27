#include<iostream>
using namespace std;
#include<unordered_map>

int main()
{
	int x[]={2,4,5,6,9,1,7,7,8};
	int *y =x;

	unordered_map<int,int>m;
#if 1
	while(*y)
	{
		if(!m.count(*y))
			m.insert(make_pair(*y,1));
		else
			m[*y]++;

		y++;
	}
#endif

#if 0
	for(int i=0;i<9;i++)
	{
		if(!m.count(x[i]))
			m.insert(make_pair(x[i],1));
		else
			m[x[i]]++;
	}
#endif

	unordered_map<int,int>::iterator it;
	for(it=m.begin(); it !=m.end();it++)
	{
		if(it->second == 1) //for unique elements 
		{
			cout<<it->first<<endl;
		}
		else //for duplicate elements
			cout<<"Duplicate element is: "<<it->first<<" Repeated: "<<it->second<<endl;
	}

}
