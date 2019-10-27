#include<iostream>
using namespace std;
#include<map>


int main()
{
	multimap<char,int>m;
#if 0 //Throws ERROR,we cannot access the elements using index in multimap
	m['A'] =2;
	m['B'] =1;
	m['C'] =3;
	m['A'] =4;
#endif
	m.insert(make_pair('A',2));
	m.insert(make_pair('B',1));
	m.insert(make_pair('C',3));
	m.insert(make_pair('A',4));
	m.insert(make_pair('D',1));
        m.insert(pair<char,int>('C',20));
	multimap<char,int>::iterator it;

#if 1 
	for(multimap<char,int>::iterator it =m.begin(); it !=m.end(); it++)
	{
		if(m.count(it->first)>1) //duplicate keys
		{
			cout<< "duplicate key: "<<it->first<<"=>"<< it->second<<endl;
		}

	}
#endif

}
