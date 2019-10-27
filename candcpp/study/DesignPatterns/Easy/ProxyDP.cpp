#include <iostream>
#include <string>
using namespace std;

/********************************************************
This is Structural Design pattern
=>This design pattern provides a surrogate(proxy) for the main object,
thereby making the direct access to the main object impossible
=>Main Objective is "protecting the main object from unexpected complexities,problems"

client is not allowed to interact directly with the RealSubject
client interacts with RealSubject via Proxy

Eg: Bank is the Subject
    CustomerAccount is the RealSubject
    DD/Cheque/ATM is the Proxy
    Customer is the Client
Here Customer cannot directly take the money from his Account
He should use either DD/Cheque/ATM source to get his money into Hand

NOTE:
Proxy is also derived(Not necessary) from Subject
Proxy interacts with RealSubject via Wrapper functions

Used in dbus(RPC) mechanism for interacting b/w one process with other processes
**********************************************************/
/*
Consider RealSubject as Server
Proxy as Proxyserver
Main function as Client
Client cannot Communicate with Server directly but it can do it using Proxyserver
*/

class Subject //Interface class 
{
	public:
		virtual void request() = 0;
};

class RealSubject : public Subject 
{
	public:
		void request() 
		{ 
			cout<<"RealSubject request()"<<endl; 
		}
};


//class Proxy : public Subject //No need of this
class Proxy 
{
	Subject *subObj;

	public:
	Proxy()
	{
		subObj = NULL; //we can also use Subject *subobj=new Subject,remove the memory allocation in below request func
	}

	~Proxy() 
	{
		delete subObj;
	}

	void CallOriginalfunc() //wrapper function 
	{
#if 0 // We can keep in this way also
		Subject *subObj =new RealSubject;
#endif

		if(subObj == NULL)
		{

			subObj = new RealSubject();
		}
		subObj->request(); //Calling RealSubject request() from Proxy request()   
	}
};

int main()
{
	Proxy p;
	p.CallOriginalfunc();
	return 0;
}


