#include<iostream>
using namespace std;

#include<list>

/***********************************************************************
insert() will call constructor,copy constructor,move constructor
emplace() will call constructor only
splice() will transfer the elements completely, will not call constructor,copy constructor,etc

NOTE:
splice() is member of list, other containers cannot use it
splice() is more efficient compared to insert(),emplace()
splice() works under C++ compiler, No need of c++11 compiler
***********************************************************************/

int main()
{
	list<int>l1,l2;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);

	l2.push_back(40);
	l2.push_back(50);
	l2.push_back(60);

	l1.splice(l1.end(),l2);

	list<int>::iterator it;
	for(it=l1.begin(); it !=l1.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<"size of l1: "<<l1.size()<<endl;
	cout<<"size of l2: "<<l2.size()<<endl; //Since l2 elements are transferred to l1,l2 now becomes empty
}
