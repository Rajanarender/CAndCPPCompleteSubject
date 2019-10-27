#include<iostream>
using namespace std;
#include<thread> //for C++ thread
#include<mutex> //for C++ mutex
#include<condition_variable> //for condition variables

/*
FYI: 
g++ -std=c++11 filename.cpp -pthread[C++11 ]

g++ filename.cpp -lpthread[C++ posix thread]
*/

/*************************************************************************
A thread/thread object becomes non-joinable for these cases
1)If the object is default constructed
2)If the object is already joined or detached
3)If the object is moved/assigned to other 

*************************************************************************/

void func()
{
	cout<<"In func\n";
}

std::mutex mobj;
void disp(int k)
{
	mobj.lock();
	cout<<"In disp "<<k<<endl;
	mobj.unlock();
}

int main()
{
	thread obj; //This is default constructed,so we cannot join this thread
	thread obj1(func);
	
	thread obj2(disp,5);
	thread obj3(disp,10);
         // (or)
	//thread obj3 = std::thread(disp,10);

	cout<<obj.joinable()<<endl;
	cout<<obj1.joinable()<<endl;
	cout<<obj2.joinable()<<endl;
	cout<<obj3.joinable()<<endl;

	if(obj.joinable()) //This is not attached to any func and self constructed,so cannot join it to main thread
	{
                cout<<"tid "<<this_thread::get_id();
		obj.join();
	}
	obj1.join();
	obj2.join();
	obj3.join();
        
	if(obj3.joinable()) //obj3 is already joined,we cannot join it back
	{
                cout<<"tid "<<this_thread::get_id();
		obj3.join();
	}

#if 0
	obj3.detach();
        
	if(obj3.joinable()) //obj3 is already detached, we cannot detached threads
	{
                cout<<"tid "<<this_thread::get_id();
		obj3.join();
	}
#endif

}

