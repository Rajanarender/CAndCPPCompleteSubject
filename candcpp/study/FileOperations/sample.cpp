#include<iostream>
using namespace std;
#include<fstream>

#include<string>

int main()
{
	ifstream obj;
	obj.open("sample.txt");

	if(!obj)
		cout<<"file does not exists,Please create it\n";

/* Character by character
	char c;
	while(!obj.eof())
	{
		obj>>c;//Reading each single character in each iteration
		cout<<c; //print to console
	}

NOTE: This is not printing the exact o/p, Spaces are getting avoided

*/

//Line by Line
        string s;
        while(getline(obj,s)) //Reading Each complete Line in each iteration
        {
        cout<<s;//print to console
        }
	obj.close();

//NOTE: This is printing the exact o/p to the console
}
