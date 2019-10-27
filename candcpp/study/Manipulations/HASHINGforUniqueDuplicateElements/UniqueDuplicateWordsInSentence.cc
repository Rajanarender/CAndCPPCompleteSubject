#include<iostream>
using namespace std;
#include<unordered_map> //Hashing
#include<string.h>

int main()
{
        //char *x = "Gesl is a MNC "; //Do not use this, Error
        char x[] = "Gesl is a MNC Gesl is MNC"; 
        char *token = strtok(x," ");//x should always be array only,V.Imp
        //map<char*,int>m; // do not use char*,Shows weird results
	unordered_map<std::string,int>m; //V.V.Imp,use std::string, Works fine

        while(token)
        {
        cout<<token<<endl;

	if(m.count(token) == 0 )
		m.insert(make_pair(token,1));
	else
		m[token]++;

        token = strtok(NULL," ");
	}

	unordered_map<std::string,int>::iterator it; //V.V.Imp,use std::string here also
	for(it=m.begin(); it !=m.end();it++)
	{
		if(it->second == 1) //for unique elements 
		{
			cout<<"Unique:"<<it->first<<endl;
		}
		else //for duplicate elements
			cout<<"Duplicate element is: "<<it->first<<" Repeated: "<<it->second<<endl;
	}
}
