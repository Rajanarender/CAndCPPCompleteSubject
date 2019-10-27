#include <iostream>
#include <vector>
#include <algorithm> //for find(),since vector does not have find() member
using namespace std;
#include<typeinfo> //typeid().name()

#include<string.h>
/***********************************************
This comes under Behavioral Pattern

Main Objective is "Any state change in one object will automatically notify and update other dependent objects"
This design pattern is One to Many Relationship,
The subject/company will send notifications/alerts to those customers who had been subscribed already with that company
If the customer gets irritated, he can unsubscribe and he will not receive any further notifications/alerts 

Ex:
Airtel company - Subject
Subscribers - Observers

Youtube -Subject
Viewers -Observers

NOTE: Instead of Register,UnRegister functions use Attach,Detach functions
************************************************/

//Interface
class observer   // base class
{
	public:
		virtual void update(char *sms)=0;
};

class HRDept : public observer
{
	public:
		void update(char *sms)
		{
			cout<<"Received Notification Message for HRDept: "<<sms<<endl; 
		}
};

class FinanceDept : public observer
{
	public:
		void update(char *sms)
		{
			cout<<"Received Notification Message for FinanceDept: "<<sms<<endl; 
		}
};

class Subject
{
                char *message;
	public:
		vector<observer*> v;
		vector<observer*> ::iterator it;

		void Register(observer *newobserver) //function to subscribe or register/attach to Subject
		{
			v.push_back(newobserver);
		}

		void unRegister(observer *observer) //Erasing/Deleting/Detach that observer
		{
#if 0 //C++11
			auto it =find(v.begin(),v.end(),observer);
#endif
			it =find(v.begin(),v.end(),observer); //find is non-member of vector class,so include algorithm header
			if(it != v.end()) //Observer present already
			{
				v.erase(it);
                                cout<<"Erased Observer is: "<<typeid(*observer).name()<<endl;
				delete observer; //V.V.Imp step ,doubtful since we didnt allocate memory for observer
			}
		}

		void notifyAll() // notifying to all subscribers who has registered(subscribed) to Subject
		{
#if 0 //C++11
			for( auto *elem : v) //C++11,*elem should only be used,since vector holds observer* 
			{
				elem->update(message);
			}
#endif      

#if 0
			for(int i =0;i<v.size();i++)
			{
				v[i]->update(message); //update() should be public in Observer class,V.V.Imp step
			}
#endif

#if 1 //This does not work,so do not use it
			for(it =v.begin();it !=v.end();it++) //begin(),end() are functions
			{
			       it->update(message);
			}
#endif
		}
#if 0
		void modifyEName(string oldname, string newname)
		{
			cout<<"Emp name is changed from "<<oldname<<" to "<<newname<<endl;
			notifyAll(); //This will call the above function
		}
#endif          
                void SMSOffer(const char *s) //const should be used Mandatory or else Error
                {
                 message =new char[strlen(s)+1]; //V.Imp
                 strcpy(message,s);
                 notifyAll();
                }
         
		~Subject()
		{
			delete message;
		} 
};

int main()
{

	Subject *bptr;
	bptr = new Subject();

#if 0 //Error,should not use register(), r[lower case] should not be used as register is keyword in C,C++,V.V.Imp  
	bptr->register(hr);
	bptr->register(f);
#endif
	//registering or subscribing to Subject
#if 0
	HRDept *hr = new HRDept();
	Finance *f = new Finance();
	bptr->Register(hr);
	bptr->Register(f);
        bptr->OfferSMS("100RC->100TalkTime");
	bptr->unRegister(hr);
#endif

        observer *ob = new HRDept(); 
	bptr->Register(ob);
        ob = new FinanceDept(); 
	bptr->Register(ob);

        bptr->SMSOffer("100RC->100TalkTime");
	bptr->unRegister(ob);
	return 0;
}

