#include<iostream>
using namespace std;

namespace:                                                                      
It is a naming convention, used in C++ to differentiate classes,functions,variables of user-defined
with those present with the SAME Names in standard libraries                        
    
Eg:

#include<cassert> //Std library
namespace gesl //user-defined assert                                                                       
{                                                                               
	void assert()
	{
		cout<<"x and y are not same\n"
	}                                                                            
}   //NOTE: No semi colon(;) for namespace as we do for class

int main()
{
	int x =10,y=20;

	if (assert(x!=y)) //std assert
	{
		cout<<"x and y are not same\n"
	}  

	gesl::assert(); //user-defined assert
}
       
Differences:
namespace need not have name, but class should have name mandatory
namespace doesnt have object ,but class should have object
namespace cannot be inherited (only nested),class can be inherited
namespace can be used by declaring as "using" and also as alias

namespace //No need of name
{
	void func(){}
}

namespace x
{
	namespace y
	{}
	namespace z
	{
		int k= 20;
	}
}

using namespace a=x::y::z
int main()
{
	cout<<a::k;
}

