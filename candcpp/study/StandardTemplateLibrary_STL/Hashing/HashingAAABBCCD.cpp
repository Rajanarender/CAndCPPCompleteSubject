#include<iostream>
using namespace std;
#include<unordered_set>

int main()
{
#if 1 //Using Pointer
	const char *x ="AAAABBBCCD";
	unordered_set<char>s;  //V.V.Imp step
	int count = 1;
	while(*x)
	{
               if(s.find(*x) == s.end()) //If element is not found in set
		{
			s.insert(*x);
			if(count > 1)
			{
				cout<<count;
			}
			cout<<*x;
			count=1; //Resetting the counter
		}
                else
		{
			count++;
		}
		
		x++;
	}
	//cout<<count; //O/p: A4B3C2D1     
	cout<<endl;
#endif

#if 0 //Using Array
	char x[]="AAAABBBCCD";
	unordered_set<char>s;

	//for(int i=0;i<(sizeof(x)/sizeof(x[0]);i++) //1st way
	//for(int i=0;i<strlen(x);i++) //2nd way
	int count =1;
	for(int i=0;x[i] != '\0';i++) //3rd way
	{
		if(s.find(x[i]) == s.end())
		{
			s.insert(x[i]);
			if(count>1)
			{
				cout<<count;
			}
			cout<<x[i];

			count =1; //Resetting the counter 
		}
		else
		{
			count++;
		}

	}
	//cout<<count; //O/p: A4B3C2D1     
	cout<<endl;
#endif

}


