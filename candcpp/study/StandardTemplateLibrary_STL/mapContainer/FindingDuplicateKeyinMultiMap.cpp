#include<iostream>
using namespace std;
#include<map> //map,multimap

/***************************************************
map,unordered_map contains unique keys
multimap contains duplicate keys 
***************************************************/

int main()
{
	multimap<int,char>m;
	multimap<int,char>::iterator it;
	m.insert(make_pair(1,'A')); //This insert() API does not work for map and unordered_map, if duplicate keys are used  
	m.insert(make_pair(2,'B'));
	m.insert(make_pair(2,'C'));
	m.insert(pair<int,char>(1,'D'));
	m.insert(pair<int,char>(2,'E'));
	m.insert(pair<int,char>(2,'E'));
	m.insert(pair<int,char>(2,'E'));
	m.insert(pair<int,char>(2,'E'));
	m.insert(pair<int,char>(2,'E'));
        cout<<m.count(2)<<endl; //For checking only a particular key repeatance
#if 1
	it =m.find(2);
	//cout<<it->second<<endl;
              //(or)
        cout<<(m.find(2)->second)<<endl;
#endif
	//for(int key=1;key<4;key++) //Here i takes Keys data only,V.V.Imp step
	for(it=m.begin();it != m.end();it++)
	{
		if(m.count(it->first) > 1) //Check whether Key is Repeating or not
		{
			cout<<"The duplicate key is: "<<it->first<<" It is Repeated: "<<m.count(it->first)<<"times"<<endl;
                        cout<<"Duplicates count for key: "<<it->first<<" is "<<( m.count(it->first)-1 )<<endl;
                        m.erase(it->first); //This deletes each repeated key-value pair
		}
		if(m.count(it->first) == 0) //Check whether particular Key is present or not
		{
			cout<<"Multimap is not having key: "<<it->first<<endl;
		}
	}

	for(it=m.begin();it != m.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

