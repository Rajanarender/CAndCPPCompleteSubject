#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/***************************************************************************************************
//member of Associative containers[map,multimap,set,multiset]
find(x.begin(),x.end(),element) //use Key as parameter,returns iterator
count(x.begin(),x.end(),element) //use key as parameter,returns integer

//member of Sequential containers[list,forward_list]
merge(x,x+boundary,y,y+boundary,v.begin())
sort(v.begin(),v.end())
reverse(v.begin(),v.end()) 
unique(v.begin(),v.end())

//Other Api's are
remove(v.begin(),v.end(),element)
replace(v.begin(),v.end(),oldelement,newelement)
***************************************************************************************************/

int main()
{

#if 1
	int x[]={2,6,4,8,6,7,6};
	vector<int>v(x,x+7); //(x,x+Numberofelements) //Parameterized constructor of vector
#if 0 //C++11
        vector<int>v{2,6,4,8,6,7,6}; //Uniform initialization
#endif

	vector<int>::iterator it;

	it = find(v.begin(),v.end(),4);
        if(it !=v.end()) //if that element is present, then only erase it
        {
	v.erase(it);
        }

	for(it=v.begin();it !=v.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;

	int cnt = count(v.begin(),v.end(),6);
	cout<<cnt<<endl;

	sort(v.begin(),v.end());      
 
	reverse(v.begin(),v.end());  
     
	remove(v.begin(),v.end(),6);      

	replace(v.begin(),v.end(),6,10); //old element,new element      

        unique(v.begin(),v.end()); //Removes similar adjacent elements

	for(it=v.begin();it !=v.end();it++)
	{
		cout<<*it<<endl;
	}
#endif

//merge()
#if 0
	int y[]={2,4,6,8}; 
        //sort(y,y+4); //If y is not sorted
	int z[]={1,3,5,7,9};
        //sort(z,z+5); //If z is not sorted
        //vector<int>v;//Throws Segmentation fault 
	vector<int>v(9); //Number of elements should be passed into the vector
	vector<int>::iterator it;

	merge(z,z+5,y,y+4,v.begin()); //It combines 2 sorted arrays into a new container beginning

	for(it=v.begin();it !=v.end();it++)
	{
		cout<<*it<<endl;
	}

#endif

}
