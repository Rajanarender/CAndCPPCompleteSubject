#include<iostream>
using namespace std;
#include<map>

/*
1.You are given elements and need to insert into a map(empty map),avoid duplicate insertion
2.Already map is loaded with few elements, now you have to find only the duplicate keys(key,value pair)
3.Already map is loaded with few elements, now you have to find only the duplicate values(key,value pair)
*/

int main()
{
	multimap<int,char>m{{1,'A'},{1,'B'}};
	multimap<int,char>::iterator it;
	it=m.find(1);
	if(it != m.end())
	{
		cout<<it->first<<"->"<<it->second<<endl;
	}
     
        cout<<m.count(1)<<endl;
}
