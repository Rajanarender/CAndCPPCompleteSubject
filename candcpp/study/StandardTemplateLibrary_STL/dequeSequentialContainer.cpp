#include<iostream>
using namespace std;

#include<deque>
#include<algorithm>

/************************************************
deque is double-ended-queue which allows insertion and deletion at both the sides

API's:
push_front(data)
pop_front()//This deletes the front element,No return type
push_back(data)
pop_back()

Access:
[]
at()
front() 
back()

size()
empty()

swap()
clear()

insert()
erase() 

Api's returning iterator
begin() 
end()
Api's returning reverse_iterator
rbegin()
rend()
*************************************************/

int main()
{
	int x[]={2,4,6,8};
	deque<int>d(x,x+4);//pass the array to constructor

	for(int i=0;i<d.size();i++)
	{
		cout<<d[i]<<endl; //Using index operator[]
#if 0
                cout<<d.at(i)<<endl; //Using member function at()
#endif
	}


	deque<int>::iterator it=find(d.begin(),d.end(),9);
	if(it != d.end())
#if 0 //We can use any of this
		if(find(d.begin(),d.end(),4) != d.end())
#endif
		{
			cout<<"9 is present in deque"<<endl;
		}
              else
               {
                  cout<<"9 is not present in deque"<<endl;
               }
                
}


