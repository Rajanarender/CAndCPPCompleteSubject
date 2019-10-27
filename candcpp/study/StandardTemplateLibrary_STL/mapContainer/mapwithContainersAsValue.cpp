#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<deque>
#include<list>

#include<set>

int main()
{
#if 0 //Passing vector as Map value
	map< string,vector<int> >m;
	m["Global"].push_back(10);
	m["Edge"].push_back(20);

	map< string,vector<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		cout<<it->second.back()<<endl;
#if 0 //Not needed
		vector<int>v = it->second;
		cout<<v.back()<<endl;
#endif
	}
#endif

#if 0 //Passing deque as Map value
	map< string,deque<int> >m;
	m["Global"].push_front(10);
	m["Edge"].push_front(20);

	map< string,deque<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		cout<<it->second.back()<<endl;
#if 0 //Not needed
		deque<int>d = it->second;
		cout<<d.back()<<endl;
#endif
	}
#endif

#if 0 //Passing list as Map value
	map< string,list<int> >m;
	m["Global"].push_front(10);
	m["Edge"].push_front(20);

	map< string,list<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
		cout<<it->second.back()<<endl;
#if 0 //Not needed
		list<int>l = it->second;
		cout<<l.back()<<endl;
#endif
	}
#endif

#if 1 //Passing set as Map value
	map< string,set<int> >m;
	m["Global"].insert(10);
	m["Edge"].insert(20);

	map< string,set<int> >::iterator it;

	for(it=m.begin();it !=m.end();it++)
	{
		cout<<it->first<<':';
                //cout<<*(it->second)<<endl;
#if 1
		set<int>s = it->second;
		set<int>::iterator it1;
                 for(it1 =s.begin();it1 !=s.end();it1++)
			cout<<*it1<<endl;//V.V.V.Imp, set does not have access specifier
#endif
	}
#endif
}
