#include<iostream>
using namespace std;

/********************************************************
static_cast: //Works At Compile time
Used for implicit conversions of Primitive data types(float to int,char to int,void*)
Used for conversions like void* to int* and int* to void*
Better than C-style casting,since it is easy to search using static keyword
and Compile time Error
FYI:works with normal,reference,ptr variables

dynamic_cast: //Works At Run time
Used for converting relavant classes like Derived to Base
Inheritance+virtual concept is mandatory for achieving dynamic_cast
FYI:works with reference,ptr variables

reinterpret_cast: //Works At Run time
Used for converting irrelavant classes which do not have relationship
FYI:works with reference,ptr variables

const_cast: //Works At Compile time, since const resides in code segment
Used for removing/modifying the constantness of the ptr/reference variables
FYI:works with reference,ptr variables
********************************************************/


class Base
{
public:
	virtual void func()
	{
		cout<<"In Base\n";
	}
};

class Derived:public Base
{
	void func()
	{
		cout<<"In Derived\n";
	}
};

void func(int *k)
{
	cout<<*k<<endl;
}

int main()
{

#if 0 //Used for implicit conversions of one type to the other
        float f= 2.78;
        int a;
        a = f;
        a = static_cast<int>(f); //Easy to search
#endif 
    
#if 0 //C-style normal casting leads to Run-time Error and difficult to find,
      //Instead static_cast results to Compile time Error and easy to resolve
	char c; //1byte
	int *x=(int*)&c; //pointer is 4bytes
	int *x=static_cast<int*>(&c);
#endif

#if 0 //Used for converting void* to int*/char*
      const void *ptr1="Global"; //V.Imp, make a Note of it 
      cout<<(char*)ptr1<<endl;

      int x=10;
      void *ptr =&x;
      cout<<(int*)ptr<<endl; //Address
      cout<<*(int*)ptr<<endl; //Value //Same conversion used in multi-threading
      cout<<static_cast<int*>(ptr)<<endl; //Address

      //Used for converting int* to void*
      int y=20;
      int *ptr2=&y;
      cout<<(void*)ptr2<<endl; //Address
      cout<<static_cast<void*>(ptr2)<<endl; //Address
#endif
    
#if 0 //We can use for converting derived class to base class,Happens at Compile time which is not Preferable 
      Derived d;
      Base &b=static_cast<Base&>(d); //works fine as dynamic_cast
      //Base *b=dynamic_cast<Base*>(&d);
      b.func();
#endif

#if 1 //dynamic_cast can be used for converting derived class to base class,Happens at Run time 
      Derived d;
      //Base *b=dynamic_cast<Base*>(&d);
      //b->func();
      Base &b=dynamic_cast<Base&>(d);
      b.func();
      
#endif

#if 0 //const_cast is used for removing the constantness of the const ptrs,references
      
      const int a = 10;
      const int *b = &a;
      int *c= const_cast<int*>(b);
      *c=20;
      //func(b); //This is wrong,sinc *b is const
      func(const_cast<int*>(b)); //Should type cast it

#endif


}
