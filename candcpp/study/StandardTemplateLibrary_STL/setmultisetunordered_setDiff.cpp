#include<iostream>
using namespace std;
#include<set> //set,multiset
#include<unordered_set> //unordered_set,supported only in C++11
/***********************************************************************
Example:
1
4
1
6

set:
unique sorted elements
Header:#include<set>
Implementation: BST
If the element is repeated once or more,then it takes the very first element data only and rejects the older data.
It displays the elements in sorted order
O/p of above Example:
1
4
6

multiset:
duplicate sorted elements
Header:#include<set>
Implementation: BST
If the element is repeated once or more,then it takes the very latest element data only and rejects the older data.
It displays the elements in sorted order
O/p of above Example:
1
1
4
6

unordered_set:
unique unsorted elements
Header:#include<unordered_set> //C++11
Implementation: BST
If the element is repeated once or more,then it takes the very latest element data only and rejects the older data.
It displays the elements in UNsorted order
O/p of above Example:
6
4
1
************************************************************************/

int main()
{
#if 0
	set<int>s; 
	set<int>::iterator it;
	s.insert(1);
	s.insert(4);
	s.insert(1);//This is not taken into set,since it is repeated 
	s.insert(6);
#endif
#if 1
	multiset<int>s; 
	multiset<int>::iterator it;
	s.insert(1);
	s.insert(4);
	s.insert(1);
	s.insert(6);
	s.insert(6);
	for(it=s.begin(); it !=s.end(); it++)
	{
		if(s.count(*it)>1) //find(),count() are members of set,multiset
		{
			cout<<"multiset is having duplicate element: "<<*it<<endl;
			cout<<"Element is repeated:"<<s.count(*it)<<"times"<<endl;
		}
	}
 
#endif
#if 0
	unordered_set<int>s; //C++11 only
	unordered_set<int>::iterator it;
	s.insert(1);
	s.insert(4);
	s.insert(1);
	s.insert(6);
#endif
        s.erase(4); //deletes only 4
        //s.erase(s.find(4),s.find(6)); //Deleting elements from value 4 to 6[excluding 6],V.V.Imp step
	for(it=s.begin();it !=s.end();it++)
	{
		cout<<*it<<endl; //dereference iterator
	}
}



