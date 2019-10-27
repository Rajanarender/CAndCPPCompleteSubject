#include<iostream>
using namespace std;

int main()
{
	string obj("Global Edge");
	//std::string obj("Global Edge"); //"using namespace std" is commented/not used 
	cout<<obj.c_str()<<endl; //c_str() api returns a ptr pointing to string obj value

	for(int i=0;i<obj.size();i++)
	{
		cout<<obj[i]<<endl;
		//cout<<obj.at(i)<<endl;
	}

	string::iterator it;
	for(it=obj.begin();it !=obj.end();it++)
	{
		cout<<*it<<endl; 
	}

}
