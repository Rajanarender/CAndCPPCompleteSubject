#include<iostream>
using namespace std;
#include<string.h> //for memset(),memcpy()

#define SIZE 3

class Test
{
	int *ptr;
	public:
		Test()
		{}

		Test(int *ar)
		{
			ptr = new int[SIZE];
			memset(ptr,0,sizeof(int)*SIZE); //For clearing the array,setting all bytes to 0
#if 1 //instead of strcpy(),we are using this way
			for(int i =0;i<SIZE;i++)
			{
				ptr[i]=ar[i];
			}
#endif
		}

		Test(const Test &obj)
		{
			ptr = new int[SIZE];
			//memcpy(ptr,obj.ptr,sizeof(int)*SIZE); //copying the memory from existing object to the new object
			for(int i =0;i<3;i++)
			{
				ptr[i]=obj.ptr[i];
			}
		}

		Test& operator=(const Test &obj)
		{
			if(this != &obj)
			{
                                Test *temp;
				temp->ptr = new int[SIZE];
				//memcpy(ptr,obj.ptr,sizeof(int)*SIZE);
				for(int i =0;i<3;i++)
				{
					temp->ptr[i]=obj.ptr[i];
				}
                               return *temp;
			}
                      //return *this;
		}

		void display()
		{
			for(int i =0;i<SIZE;i++)
			{
				cout<<ptr[i]<<endl;
			}
		}

};

int main()
{
	//char x[]="Raja";
	int x[]={2,4,5};
	Test obj1(x),obj2(obj1),obj3;
	obj1.display();
	obj2.display();
	obj3=obj1;
	obj3.display();
}
