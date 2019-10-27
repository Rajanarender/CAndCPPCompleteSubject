#include<iostream>
//using namespace std;
//#include<string.h> //all str apis like strcpy,strcat,etc
#include<string> //for string class apis
#include<string.h>

int main()
{
	//std::string s("Gesl is a MNC");
	std::string s ="Gesl is a MNC"; //Either of s(),s=
	std::cout<<s<<"\n";
        std::cout<<s.substr(5,2);  //is //substr(position,lengthofsubstring)
	std::cout<<s.c_str()<<"\n"; //Gets the std::string in c-style format
	std::cout<<s.size()<<"\n"; //size(),length() both are same

	std::cout<<s.length()<<"\n"; //No need of strlen

        std::string s1=s; //No need of strcpy
	std::cout<<"s1:"<< s1<<"\n";
   
        std::string s2("Tech"),s3;
        s3 = s1 + s2; //No need of strcat
	if(s1 == s2) //No need of strcmp
	{
		std::cout<<"s3:"<< s3<<"\n";
	}

	for(int i=0;i<s.size();i++)
	{
		std::cout<<s[i]; //character by character, each index holds a single character
                std::cout<<s.at(i);
	}

	std::string::iterator it;
	for(it = s.begin();it != s.end(); it++)
	{
		std::cout<<*it; //always dereference iterator
	}

	std::string s4 = "Hello";
	std:: string s5 = "World";
	s4.swap(s5);
	cout<<s4<<s5;
	if (s4.compare(s5) != 0)
	{
		cout<<"Both strings are not equal";
	}

#if 1 //We cannot pass std::string to strtok directly, so use c_str() and copy to char*, then pass to strtok
	char *x = new char[s.length()+1];
	strcpy(x,s.c_str()); // copy c-style to char*
	//char *token = strtok(s.c_str()," "); //Error:Invalid conversion of const char* to char*
	char *token = strtok(x," ");
	while(token)
	{
		std::cout<<token<<"\n";
		token = strtok(NULL," ");
	}
#endif

	//How to find whether a substring is present in the string ?
		if(s.find("MNC") != std::string::npos) //max value for size_t
		{
			std::cout<< "The substring MNC is found at:" <<s.find("MNC"); //10
		}

       
       
}
