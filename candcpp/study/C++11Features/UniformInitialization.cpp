#include<iostream>
using namespace std;
#include<vector>
#include<map>

/*******************************************************************
Uniform Intialization:
array Initialization in normal,class
vector Initialization
map Initialization
ptr Initialization with nullptr
string Initialization
********************************************************************/

struct Sam 
{
	int l;
	string m;
}S{100,"Global"}; //strcuct Declaration cum Object creation

class Test
{
	int a[3];

	public:
	Test():a{2,3,4} //Array Initialization
	{
		//a{2,3,4};
	}
	void display()
	{
		for(int i =0;i<3;i++)
		{
			cout<<a[i]<<endl;
		}
	}
};

int main()
{
          Test obj;
          obj.display();
	//Instead of pushing into the vector multiple times,we can use C++11 initialization feature
	/*
	   vector<int>v;
	   v.push_back(15);
	   v.push_back(25);
	   v.push_back(35);
	 */

	/* 
	   int y[]={15,25,35}; //Taking the elements into an array and then assigning
	   vector<int>v(y,y+3);
	   for(auto i: v)
	   cout<<i<<endl;
	 */

	vector<int>v{15,25,35}; 
	//vector<int>v = {15,25,35};
        map<string,int>mp{ {"Global",1},{"Edge",2} };
        //map<string,int>mp={ {"Global",1},{"Edge",2} };

	cout<<S.l<<S.m<<endl;
	//struct Sam S1 = {200,"Edge"}; //C++98
	struct Sam S1{200,"Edge"}; //C++11,Generic struct object creation
	cout<<S1.l<<S1.m<<endl;

	//int *x=NULL;
	int *x{nullptr}; //(or) int *x{};
	cout<<x<<endl;

	//int arr[]={2,4,5};
	int arr[]{2,4,5};
	cout<<arr[0]<<endl;

	//string text="Hello";
	string text{"Hello"};
	cout<<text<<endl;
}
