#include<iostream>
using namespace std;
#include<vector>

/*********************************************************************
If the container holds Primitive data types we can use either insert or emplace, 
since primitive data types dont invoke constructor,copy/move constructor
vector<int> v;

If the container holds Used defined types like class,etc then emplace is most preffered than insert
emplace only constructs the object
insert constructs and copy's/moves the object to other, leading to less efficiency
emplace is more efficient
class A{};
vector<A>v;

v.insert(v.end(),10) == v.push_back(10);
v.emplace(v.end(),10) == v.emplace_back(10);

deque<A>d;

d.insert(d.begin(),10) == v.push_front(10);
d.emplace(d.begin(),10) == v.push_front(10);
NOTE:insert and emplace need 2 parameters(1st element's position of element,2nd element value)

*********************************************************************/

class A
{
	int k;
	int l;
	int m;
	public:
	A(int x):k(x)
	{
		cout<<"1Args Param constructor is called\n";
	}

	A(int x,int y):l(x),m(y)
	{
		cout<<"2Args Param constructor is called\n";
	}
 
        A(const A &obj):l(obj.l)
        {

		cout<<"Copy constructor is called\n";
        }        


};

int main()
{
	vector<A>v;

#if 0 //1Args Param constructor and copy constructor is called
	v.insert(v.end(),10); 
	v.push_back(10);
#endif

#if 1 //1Args Param constructor is called only
	v.emplace(v.end(),10); 
	v.emplace_back(10);
#endif

#if 0 //2Args Param constructor and copy constructor is called
	v.push_back(A(10,20)); 
#endif

	v.emplace_back(10,20); //2Args Param constructor is called only

#if 0
	v.insert(v.begin(),30,40); //1Args Param constructor and copy constructor(this is called mutliple times)
#endif

#if 0
	v.insert(v.begin(),A(30,40)); //2Args Param constructor and copy constructor is called
#endif

	v.emplace(v.begin(),30,40); //Only 2Args Param constructor is called
}
