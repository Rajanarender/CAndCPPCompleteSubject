#include<iostream>
using namespace std;
#include<map> //map,multimap
#include<unordered_map> //unordered_map,supported only in C++11
#include<algorithm> //merge(),sort(),reverse(),unique(),replace(),remove()
/***********************************************************************
Example:
1=>'A'
2=>'B'
2=>'C'
1=>'D'

map:
unique sorted Keys,duplicate values
m[] //index is allowed
Header: #include<map> 
Implementation: BST
If the key is repeated once or more,then it takes the very latest key-value pair
and rejects the oldest.It displays key-value pair in sorted order
O/p of above Example:
1=>'D'
2=>'C'

multimap:
duplicate sorted Keys,duplicate values
m[] //index is not allowed
Header: #include<map>
Implementation: BST
If the key is repeated once or more, it keeps all the key-value pair including duplicates in Sorted order 
O/p of above Example:
1=>'A'
1=>'D'
2=>'B'
2=>'C'

unordered_map: [Also called as HASH table,similar to map with keys unsorted]
unique unsorted Keys,duplicate values
m[] //index is allowed
#include<unordered_map>
Implementation: HASH Table
NOTE: unordered_map works only in C++11
If the key is repeated once or more,then it takes the very latest key-value pair
and rejects the oldest.It displays key-value pair in Unsorted order
O/p of above Example:
2=>'C'
1=>'D'
************************************************************************/

int main()
{
#if 0
	map<int,char>m;
	map<int,char>::iterator it;
        m[1]='A'; //index is a member of map
        m[2]='B';
        m[2]='C';
        m[1]='D';
#endif 

#if 0
	multimap<int,char>m;
	multimap<int,char>::iterator it;
	//m[0]='Z'; //index not a member of multimap,V.V.Imp step
#endif

#if 1
	unordered_map<int,char>m; //C++11 only
	unordered_map<int,char>::iterator it;
        m[1]='A'; //index is a member of map
        m[2]='B';
        m[2]='C';
        m[1]='D';
#endif 

	m.insert(make_pair(1,'A')); //This insert() API does not work for map and unordered_map, if duplicate keys are used,V.V.Imp step  
	m.insert(make_pair(2,'B'));
	m.insert(make_pair(2,'C'));
	m.insert(pair<int,char>(1,'D'));
	for(it=m.begin();it != m.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

