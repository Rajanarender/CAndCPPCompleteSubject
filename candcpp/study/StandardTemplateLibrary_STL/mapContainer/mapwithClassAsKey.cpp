#include<iostream>
using namespace std;
#include<map>

class Test
{
	string str;
	int var;

	public:
#if 1 //Default constructor,Mandatory for Explicit constructor call Test(),V.V.Imp step
        Test()
        {
         str = ' '; //space character
         var =0;
        }
#endif
	Test(string s,int num)
	{
		str=s;
		var=num;
	}

#if 1 //Sort the keys(class attributes) using operator overloading,V.V.Imp step
	bool operator<(const Test&obj) const
	{
		if(str != obj.str)
			return str<obj.str;
		else if(str == obj.str)
			return var<obj.var;
	}
#endif
	void display() const
	{
		cout<<"Name: "<<str<<","<<" variable: "<<var<<endl;
	}
};

int main()
{
	map<Test,int>m; //class as Key
	m[Test("Raja",10)] =1;
	m[Test("Suri",20)] =2;
	m[Test("Bharath",30)] =3; //Previous same key will be overridden with this key-value pair
	//m.insert( make_pair(Test(40,"Raja"),3) ); //same key cannot be inserted
	//m.insert( pair<int,Test>(Test(50,"Ammi"),4) );
	for(map<Test,int>::iterator it=m.begin();it != m.end(); it++)
	{
		cout<<"Key is:";
		it->first.display();
		cout<<" Value is:"<<it->second<<endl;
	}
}
