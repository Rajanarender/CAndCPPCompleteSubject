#include<iostream>
using namespace std;

#include<map>

/*****************************************************
map<keydatatype,valuedatatype>m;
m[key]=value;
NOTE: Keys are always arranged in Ascending order in Map

if( m.find(key) != m.end() ) //existing
{
cout<<"Key is already present in map";
}
if( m.find(key)) == m.end() ) //Not existing
{
cout<<"Key is not there in map";
m.insert( make_pair() );  //If you want you can insert this 
}

for(it=m.begin();it !=m.end();it++) //traverse and display
{
cout<<it->first; //Key
cout<<it->second; //value
}

All these api's return iterator
it = m.begin()
it = m.end()
it = m.find(key)

int x=m.count(key) //count returns the number of times particular key is repeated including the key itself

Api that use iterator as parameter
m.erase(key)
m.erase(it)
m.erase(m.begin());
m.erase(m.end());
m.erase(m.find(key));
m.erase(m.begin(),m.find(key));
m.erase(m.find(key),m.end());
m.insert(it);
m.insert(make_pair());
m.insert( pair<keydatatype,valuedatatype>() )

******************************************************/

int main()
{
	map<string,int>m;
	m["Raja"] =5;
	m["Damu"] =7;
	m["Suri"] =9;
	m["Ammi"] =11;
	m["Raja"] =145; //The previous value that is paired with "Raja" is replaced with this value 

        m.insert({"Vishnu",100}); //C++11,uniform initialization      
        m.insert({"Zibra",500}); //C++11,uniform initialization      
	m.insert(pair<string,int>("Raja",100)); //We cannot insert existing key using this API
	m.insert(make_pair("Raja",500)); //We cannot insert existing key using this API
        cout<<"Size of map is: "<<m.size()<<endl;        

#if 0 //erase will delete b/w 1st specified argument to 2nd specified argument[Excluding 2nd specified argument]
        m.erase("Damu");
        m.erase(m.find("Damu"),m.find("Suri"));
        m.erase(m.begin(),m.find("Damu"));
        //m.erase(m.find("Damu"),m.begin()); //Segmentation fault,Wrong way of passing arguments
        m.erase(m.find("Damu"),m.end());
        //m.erase(m.end(),m.find("Damu")); //Segmentation fault,Wrong way of passing arguments
#endif 

#if 0 //3types of insert()
	m.insert(pair<string,int>("Zadran",900) ); //insert key-value pair using 1 parameter
	m.insert(make_pair("Rashid",345));

	it=m.begin();                              //insert key-value pair at specified position using 2parameters
	m.insert(it,pair<string,int>("Mark",650))

	map<string,int>m1;
	m1.insert(m.begin(),m.find("Raja"));
#endif

#if 0  //3types of erase()
	m.erase("Damu");                               //Erase key-value pair using key

	map<string,int>::iterator it = m.find("Suri"); //Erase key-value pair using iterator
	m.erase(it);

	it = m.find("Ammi");
	m.erase(it,m.end());                           //Erase key-value pair using range

	map<string,int>m1;
	m1.erase(m.begin(),m.find("Raja"));
	m1.erase(m.find("Raja"),m.begin());

#endif

//1st Method for Traversing
	for(map<string,int>::iterator it=m.begin();it !=m.end();it++) //To display all the key-value pairs
	{
		cout<<it->first<<"=>"<<it->second<<endl;
	}
#if 0
	cout<<"We can use find(),begin(),end() API's instead of iterator as shown below"<<endl;
	cout<<m.find("Raja")->first<<"=>"<<m.find("Raja")->second<<endl;
	cout<<m.begin()->first<<"=>"<<m.begin()->second<<endl;

//2nd Method for Traversing
	while(!m.empty())
	{
		cout<<m.begin()->first<<"=>"<<m.begin()->second<<endl;
		m.erase(m.begin()); //V.V.Imp, only when erase, it will be empty at one stage
	}

	if( m.find("Ammi") != m.end() )
	{
		cout<<"Raja is present in Map\n";
	}
	else
	{
		cout<<"Specified Key is not present\n";
	}
#endif
}



