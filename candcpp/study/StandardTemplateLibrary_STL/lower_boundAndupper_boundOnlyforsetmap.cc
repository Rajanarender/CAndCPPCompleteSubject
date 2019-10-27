#include<iostream>
using namespace std;

#include<set>
#include<map>

/***********************************************************************
lower_bound(key) - returns iterator to the same key //Similar to find()
upper_bound(key) - returns iterator to the next following key, V.V.Imp 
m.erase(m.lower_bound(),m.upper_bound()); 

NOTE: We use lower_bound(),upper_bound() apis in erase to 
delete the elements present in b/w the container other than begin and end elements

erase - begin to end
erase - begin to find // begin to in b/w
erase - find to end // in b/w to end
erase - lower_bound to upper_bound // in b/w to in b/w
***********************************************************************/


int main()
{
#if 0
	set<int>s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.erase(s.lower_bound(20),s.upper_bound(40)); //20 to 40 range elements are erased 10,50
        //s.erase(s.begin()+1,s.end()-1);
        //s.erase(20,40);
        //s.erase(s.find(20),s.find(40)); //10,40,50
	set<int> :: iterator it;
	for(it = s.begin(); it !=s.end(); it++)
	{
		cout<<*it<<endl;
	}
#endif

	map<char,int>m;
	m['a'] = 10;
	m['b'] = 20;
	m['c'] = 30;
	m['d'] = 40;
	m['e'] = 50;
        //m.erase(m.begin(),m.find('c')); //30,40,50
        //m.erase(m.find('c'),m.end()); //10,20
        //m.erase(m.begin(),m.end()); //map will be empty

        //m.erase(m.begin(),m.lower_bound('c')); //30,40,50
        //m.erase(m.begin(),m.upper_bound('c')); //40,50
	m.erase(m.lower_bound('b'),m.upper_bound('d')); //10,50

	map<char,int>::iterator it;

	for(it = m.begin(); it !=m.end(); it++)
	{
		cout<<it->first <<" "<<it->second<<endl;
	}
}
