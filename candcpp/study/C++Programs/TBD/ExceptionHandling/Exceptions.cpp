#include<iostream>
using namespace std;

/*************************************************
try{} block
throw statement;
catch(datatype statement){} block 

NOTE: catch() is similar to func()

*************************************************/

#if 0 
//Case 1: (Direct throw statement) with condition check
int main()
{
	bool x= true;
	try
	{
		if(x==true)
			throw x;
	}

	catch(bool x)
	{
		cout<<"Exception is:"<<x<<endl;
	}
}
#endif

#if 0
//Case 2: (throw statement with condition check) within the function
void func(bool x)
{
	if(x==true)
		throw x;
}

int main()
{
	bool x= true;
	try
	{
		func(x);
	}

	catch(bool x)
	{
		cout<<"Exception is:"<<x<<endl;
	}
}
#endif


#if 0
//Case 3: (throw statement with condition check) within the class
class Test
{
	public:
		Test(bool y)
		{
			if(y==true)
				throw y;
		}
};

int main()
{
	bool x= true;
	try
	{
		Test obj(x); //class object
	}

	catch(bool x)
	{
		cout<<"Exception is:"<<x<<endl;
	}
}
#endif

#if 1
//Case 3: (throw statement with condition check) within the class
class Test
{
	public:
		Test()
		{
                char *m = new char[99999999999999999];
                delete []m;
		}
};

int main()
{
	try
	{
		Test obj(); //class object
	}

	catch(bad_alloc &e) //reference
	{
		cout<<"Exception is:"<<e.what()<<endl;
	}
}
#endif










