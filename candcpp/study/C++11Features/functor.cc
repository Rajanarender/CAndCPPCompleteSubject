#include<iostream>
using namespace std;
#include<vector>
#include<algorithm> //for_each, transform

void func(int x) //Argument is int since vector holds int type
{
	cout<<x<<endl;
}

class X
{
public:
	void operator()(int x) //should be public mandatory
	{
		cout<<x<<endl;
	}

}; 

int main()
{
	//vector<int>v{2,4,6};
	vector<int>v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	for_each(v.begin(),v.end(),func); //This will call func for each vector element

        X obj;
	for_each(v.begin(),v.end(),obj); //This will call obj functor for each vector element

#if 0 //functor should have valid return type other than void, since this return type gets stored in v2 of std::transform() api       
        vector<int>v2;
        transform(v.begin(),v.end(),v2.begin(),obj); //This will call obj functor and store its return type in v2 ,for each vector element
#endif
}
