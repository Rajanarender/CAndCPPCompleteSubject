#include<iostream>
using namespace std;

#include<vector>

/***********************************************************************************
NOTE: Any container starts from 0th index

vector Memory allocation
By default vector allocates memory as per capacity() API,which leads to memory wastage
To use Memory efficiently, we can fix the memory using reserve() API

size() =>No. of elements present in vector

capacity() =>max elements that can be accommodated within the vector
This keeps changing dynamically(doubled,tripled) as per the elements being pushed
Due to capacity changes,vector memory gets wasted

reserve() =>This restricts the vector growth/capacity dynamically upto specified argument
reserve(5); //In whatever way, we push 5 elements, the vector capacity remains 5 only
************************************************************************************/

vector<int> v;
vector<int>::iterator it; //iterator class is a Nested class in any container class
int main()
{

#if 1  
        //We can save the memory using reserve(numberscount) API
	v.reserve(17); //capacity remains 17 for 1st 17 elements,after that it capacity keeps doubling as usual
#endif
	v.push_back(1);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc =1
	v.push_back(2);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=2
	v.push_back(3);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=4
	v.push_back(4);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=4
	v.push_back(5);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=8
	v.push_back(6);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=8
	v.push_back(7);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=8
	v.push_back(8);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=8
	v.push_back(9);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(10);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(11);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(12);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(13);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(14);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(15);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(16); 
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=16
	v.push_back(17);
        cout<<v.size()<<","<<v.capacity()<<'\n'; //cc=32
	return 0;
}
